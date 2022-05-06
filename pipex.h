#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h> //open()
# include <unistd.h> // pipe(), dup2(), access(), execve(), fork()
# include <sys/wait.h> //waitpid()
# include <stdbool.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# define READ 0
# define WRITE 1

/* temp*/
#include <sys/errno.h>
#include <string.h>
#include <stdio.h>
extern int errno;

typedef struct s_childlist
{
	char				**command;
	int					pid;
	int					fd_read;
	struct s_childlist	*next;
}	t_childlist;

int		execute_job(int argc, char **argv, char **paths);
bool	is_valid_argc(int argc, char **argv);
bool	is_heredoc(const char *argv1);
char	**get_paths(char **envp);
void	open_files(int argc, char **argv, int *file_fd);
int		get_stdin_newfd(char *limiter);
bool	is_limiter(char *line, char *limiter);
t_list	*get_cmdlist(int argc, char **argv);
void	reset_stdin(int *file_fd);
void	reset_stdout(int *file_fd, int *pipe_fd, t_childlist *childlist);
void	execute_cmd(char **cmd, char **paths);
char	*get_full_path(char *cmd, char **paths);
void	wait_children(t_childlist **childlist);
t_childlist	*lstlast(t_childlist *lst);
void	lstadd_back_cmd(t_childlist **lst, t_childlist *new);
t_childlist	*lstnew_cmd(char **command);
t_childlist	*get_childlist(int argc, char **argv);

#endif
