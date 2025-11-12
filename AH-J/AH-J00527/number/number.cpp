#include<stdio.h>
#include<string.h>
#define MAXN 1000005
char s[MAXN];
int a[10];
void write(int x,int n){
	if(x==1)for(int i=1;i<=n;i++)putchar('1');
	if(x==2)for(int i=1;i<=n;i++)putchar('2');
	if(x==3)for(int i=1;i<=n;i++)putchar('3');
	if(x==4)for(int i=1;i<=n;i++)putchar('4');
	if(x==5)for(int i=1;i<=n;i++)putchar('5');
	if(x==6)for(int i=1;i<=n;i++)putchar('6');
	if(x==7)for(int i=1;i<=n;i++)putchar('7');
	if(x==8)for(int i=1;i<=n;i++)putchar('8');
	if(x==9)for(int i=1;i<=n;i++)putchar('9');
	if(x==0)for(int i=1;i<=n;i++)putchar('0');
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	int sn=strlen(s);
	for(int i=0;i<sn;i++)
		if(s[i]>='0'&&s[i]<='9')
			a[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		if(a[i])
			write(i,a[i]);
	return 0;
}
