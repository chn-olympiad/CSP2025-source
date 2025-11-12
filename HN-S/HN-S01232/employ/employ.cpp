#include <bits/stdc++.h>
using namespace std;

const int N = 505, p = 998244353;
int n, m, c[N];
char s[N];

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d%s", &n, &m, s);
	bool f = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &c[i]);
		if (s[i-1] == '0')
		{
			f = 1;
		}
	}
	if (m == 1)
	{
		
	}
	if (m == n)
	{
		if (f == 1)
		{
			printf("0");
		}
		
		return 0;
	}
	if (!f)
	{
		
	}
	return 0;
}

