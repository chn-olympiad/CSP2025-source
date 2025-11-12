#include<stdio.h>
#include<string.h>
char s[1000001];
int len, num[10];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s);
	len = strlen(s);
	for(int i = 0; i < len; i++)
	if(s[i] >= '0' && s[i] <= '9')
	num[s[i] - '0']++;
	for(int i = 9; i >= 0; i--)
	for(int j = 0; j < num[i]; j++)
	putchar(i + '0');
	return 0;
}