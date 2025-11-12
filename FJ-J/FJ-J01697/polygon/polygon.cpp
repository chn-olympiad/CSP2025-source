#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 10;
const int MOD = 998244353;

int mx[N][N], num[N], d[N], n, ans;

void dfs(int num, int k, int s, int ma)
{
	if (num >= 3)
	{
		if (s > (2 * ma))
		{
			ans = (ans + 1) % MOD;
		}
	}
	for (int i = k + 1; i <= n; i++)
	{
		dfs(num + 1, i, s + d[i], max(ma, d[i]));
	}
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", d + i);
	}
	if (n <= 20)
	{
		dfs(0, 0, 0, 0);
	}
	else
	{
		sort(d + 1, d + 1 + n);
		for (int i = 1; i <= n; i++)
		{
			num[i] = num[i - 1] + d[i];
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j <= n; j++)
			{
				if (i == j)
				{
					mx[i][j] = d[i];
				}
				else
				{
					mx[i][j] = mx[j][i] = max(mx[i][j - 1], d[j]);
				}
			}
		}
		for (int i = 1; i < (n - 1); i++)
		{
			for (int j = i + 2; j <= n; j++)
			{
				if ((num[j] - num[i - 1]) > (2 * mx[i][j]))
				{
					ans = (ans + 1) % MOD;
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}
