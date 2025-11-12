#include<bits/stdc++.h>
using namespace std;

char s[1000100];
int cnt[10];
int l;

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s + 1);
	l = strlen(s + 1);
	for(int i = 1; i <= l; i++)
		if(s[i] >= '0' && s[i] <= '9')
			cnt[s[i] - '0']++;
	for(int i = 9; i >= 0; i--)
		while(cnt[i]--)
			printf("%d",i);
	return 0;
} 
