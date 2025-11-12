#include <bits/stdc++.h>
using i64 = long long;
using ui64 = unsigned long long;
using namespace std;
const int N = 505, mod = 998244353;
int T = 1, n, m, c[N], ans, p[N];
string s;
bool vis[N];
void dfs (int dep)
{
	if (dep > n)
	{
		int cnt = 0, C = 0;
		for (int i = 1; i <= n; ++ i)
		{
			int j = p[i];
			if (cnt >= c[j])
			{
				++ cnt;
				continue;
			}
			if (s[i] ^ '1')
				++ cnt;
			else
				++ C;
		}
		ans += C >= m;
		return;
	}
	for (int i = 1; i <= n; ++ i)
		if (! vis[i])
			vis[i] = 1,
			p[dep] = i,
			dfs (dep + 1),
			vis[i] = 0;
			
}
void solve ()
{
	cin >> n >> m >> s;
	s = " " + s;
	for (int i = 1; i <= n; ++ i)
		cin >> c[i];
	dfs (1);
	cout << ans;
}
signed main ()
{
	ios::sync_with_stdio (0);
	cin.tie (0);
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	while (T --)
		solve ();
	return 0;
}
