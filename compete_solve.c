#include "apue.h"

static void charatatime(char*);

int main(void) {
	pid_t pid;

	TELL_WAIT();

	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if (pid == 0){
		WAIT_PARENT();
		charatatime("out put from child\n");
	}else {
		charatatime("out put from paretn\n");
		TELL_CHILD(pid);
	}
	
	exit(0);
}

static void charatatime(char *str){
	char *ptr;
	int c;

	setbuf(stdout, NULL); //set unbuffered
	for (ptr = str; (c = *ptr++) != 0;)
		putc(c,stdout); //out char by char
}
