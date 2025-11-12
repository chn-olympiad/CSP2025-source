#include <bits/stdc++.h>
using namespace std;
int n, t, a[100005], b[100005], c[100005], ans;
void dfs(int j, int k, int l, int x, int sum)
{
	if (x == n + 1)
	{
		ans = max(ans, sum);
		return ;
	}
	if (j + 1 > n / 2)
	{
		if (k + 1 > n / 2)
		{
			dfs(j, k, l + 1, x + 1, sum + c[x]);
		}
		else if (l + 1 > n / 2)
		{
			dfs(j, k + 1, l, x + 1, sum + b[x]);
		}
		else
		{
			dfs(j, k, l + 1, x + 1, sum + c[x]);
			dfs(j, k + 1, l, x + 1, sum + b[x]);
		}
	}
	else if (k + 1 > n / 2)
	{
		if (j + 1 > n / 2)
		{
			dfs(j, k, l + 1, x + 1, sum + c[x]);
		}
		else if (l + 1 > n / 2)
		{
			dfs(j + 1, k, l, x + 1, sum + a[x]);
		}
		else
		{
			dfs(j, k, l + 1, x + 1, sum + c[x]);
			dfs(j + 1, k, l, x + 1, sum + a[x]);
		}
	}
	else if (l + 1 > n / 2)
	{
		if (j + 1 > n / 2)
		{
			dfs(j, k + 1, l, x + 1, sum + b[x]);
		}
		else if (k + 1 > n / 2)
		{
			dfs(j + 1, k, l, x + 1, sum + a[x]);
		}
		else
		{
			dfs(j + 1, k, l, x + 1, sum + a[x]);
			dfs(j, k + 1, l, x + 1, sum + b[x]);
		}
	}
	else
	{
		dfs(j + 1, k, l, x + 1, sum + a[x]);
		dfs(j, k + 1, l, x + 1, sum + b[x]);
		dfs(j, k, l + 1, x + 1, sum + c[x]);
	}
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i] >> b[i] >> c[i];
		}
		ans = 0;
		dfs(0, 0, 0, 1, 0);
		cout << ans << '\n';
	}
	return 0;
}
