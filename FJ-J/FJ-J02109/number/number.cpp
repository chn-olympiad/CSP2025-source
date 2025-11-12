#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
using namespace std;
char s[1000005];
int a[1000005];
int top=0;
int cmp(int a,int b){return a>b;}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	for(int i=0,l=strlen(s);i<l;i++){
		if('0'<=s[i]&&s[i]<='9')
			a[++top]=s[i]-'0';
	}
	sort(a+1,a+top+1,cmp);
	int f=0;
	for(int i=1;i<=top;i++) if(a[i]!=0) f=1;
	if(f==1) for(int i=1;i<=top;i++)
		printf("%d",a[i]);
	else putchar('0');
	return 0;
}

