#include<stdio.h>
char s[1000001],*p=s,j;
int a[10],i,k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	do{
		if(*p>='0'&&*p<='9')++a[(*p)^48];
	}while(*++p);
	for(i=9;~i;--i)
		for(;a[i];--a[i])
			putchar(i^48);
	return 0;
}
