#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
const int N = 100010;
int pa[N], st[N], a[N], n, res, m;
string p;
void dfs(int u)
{
	if (u == n + 1)
	{
		int fail = 0, ans = 0;
		for (int i = 1; i <= n; i ++ )
		{
//			cout << pa[i] << ' ';
			if (fail >= a[pa[i]])
			{
				fail ++ ;
				continue;
			}
			if (p[i] == '0')
			{
				fail ++ ;
				continue;
			}
			ans ++ ;
		}
//		cout << ans << ' ' << fail << '\n';
		if (ans >= m) res ++ ;
		return ;
	}
	for (int i = 1; i <= n; i ++ )
	{
		if (!st[i])
		{
			st[i] = true;
			pa[u] = i;
			dfs(u + 1);
			st[i] = false;
		}

	}
}
signed main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> p;
	p = " " + p;
	for (int i = 1; i <= n; i ++ )
	{
		cin >> a[i];
	}
	if (n <= 18)
	{
		dfs(1);
		cout << res << '\n';
	}
	else if (m == 1)
	{
		int ans = 1, t = 0;
		for (int i = n; i >= 2; i -- )
		{
			ans *= i;
			ans %= mod;
		}
//		for (int i = 1; i <= t; i ++ )
//		{
//			ans *= i;
//			ans %= mod;
//		}
		cout << ans << '\n';
	}
	else
	{
		int ans = 1, t = 0;
		for (int i = 1; i <= n; i ++ ) if (a[i] == 0) t ++ ;
		if (n - t < m)
		{
			cout << 0;
			return 0;
		}
		for (int i = n; i >= 2; i -- )
		{
			ans *= i;
			ans %= mod;
		}
//		for (int i = 1; i <= t; i ++ )
//		{
//			ans *= i;
//			ans %= mod;
//		}
		cout << ans << '\n';
	}
	return 0;
}
