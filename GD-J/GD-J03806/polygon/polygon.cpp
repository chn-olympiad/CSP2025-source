#include <bits/stdc++.h>
using namespace std;

const int N = 200000, M = 5001, inf = 0x3f3f3f3f, dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0}, mod = 998244353;

int a[N], ans = 0, n, m, b[N];

void dfs (int u, int sum, int maxn, bool flag)
{
	if (flag && m >= 3 && sum > maxn * 2)
	{
		for (int i = 1; i <= m; i++)
		{
//			cout << b[i] << " ";
		}
//		cout << "\n";
		ans++;
		ans %= mod;
	}
	if (u > n)
	{
		return ;
	}
	b[++m] = u;
	dfs (u + 1, sum + a[u], max (maxn, a[u]), 1);
	b[m--] = 0;
	dfs (u + 1, sum, maxn, 0);
}

signed main ()
{
	ios::sync_with_stdio (0); cin.tie (0); cout.tie (0);
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	dfs (1, 0, 0, 0);
	cout << ans % mod;
	return 0;
}

/*
5
1 2 3 4 5

9

----------

5
2 2 3 8 10

6
*/
