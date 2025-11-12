#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n;
int a[15];
char s[N];

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s+1);
	n = strlen(s+1);
	for(int i = 1; i <= n; ++i)
	{
		if('0' <= s[i] && s[i] <= '9') ++a[s[i] - '0'];
	}
	for(int i = 9; ~i; --i)
	{
		while(a[i]) --a[i], putchar(i | 48); 
	}
	return 0;
}
