#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e06 + 7;

int n, m;

int a[MAXN];

char s[MAXN];

bool cmp(int a, int b)
{
	return a > b;
}

signed main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	scanf("%s", s + 1), n = strlen(s + 1);
	
	for(int i = 1; i <= n; i++)
	{
		if('0' <= s[i] and s[i] <= '9') 
			a[++m] = s[i] - '0';
	}
	
	sort(a + 1, a + m + 1, cmp);
	
	for(int i = 1; i <= m; i++)
		printf("%d", a[i]); 
	
	return 0;
}
