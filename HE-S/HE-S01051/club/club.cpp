#include <bits/stdc++.h>
using namespace std;

long long zu, a[100005][5], num, n;

void dfs (int r, int x, int y, int z, long long m)
{
	if (r > n)
	{
		num = max(num, m);
		return;
	}
	if (x < n/2)
	{
		dfs(r+1, x+1, y, z, m+a[r][1]);
	}
	if (y < n/2)
	{
		dfs(r+1, x, y+1, z, m+a[r][2]);
	}
	if (z < n/2)
	{
		dfs(r+1, x, y, z+1, m+a[r][3]);
	}
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &zu);
	while (zu--)
	{
		scanf("%lld", &n);
		num = 0;
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= 3; j++)
			{
				scanf("%lld", &a[i][j]);
			}
		}
		dfs(1, 0, 0, 0, 0);
		printf("%lld\n", num);
	}
	
	return 0;
}
