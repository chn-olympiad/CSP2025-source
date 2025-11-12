#include <bits/stdc++.h>
using i64 = long long;
using ui64 = unsigned long long;
using namespace std;
const int N = 1e4 + 5, M = 2e6 + 5, K = 15;
int T = 1, n, m, k, u, v, w, c[N], d[K][N], f[N], mm, nn;
i64 res = 1e18;
int Find (int x)
	{return f[x] ^ x ? f[x] = Find (f[x]) : x;}
struct node{int u, v, w;}a[M], b[M];
void dfs (int dep, i64 s)
{
	if (s >= res)
		return;
	if (dep > k)
	{
		for (int i = 1; i <= n + k; ++ i)
			f[i] = i;
		for (int j = 1; j <= mm; ++ j)
			b[j] = a[j];
		sort (b + 1, b + mm + 1, [](node a, node b){return a.w < b.w;});
		int cnt = 0;
		i64 ans = s;
		for (int i = 1; i <= mm; ++ i)
		{
			int u = b[i].u, v = b[i].v, fu = Find (u), fv = Find (v);
			if (fu ^ fv)
			{
				++ cnt;
				ans += b[i].w;
				if (ans >= res)
					return;
				f[fu] = fv;
				if (cnt == nn - 1)
					break;
			}
		}
		res = min (res, ans);
		return;
	}
	dfs (dep + 1, s);
	for (int i = 1; i <= n; ++ i)
		a[i + mm] = {dep + n, i, d[dep][i]};
	mm += n;
	++ nn;
	dfs (dep + 1, s + 1ll * c[dep]);
	-- nn;
	mm -= n;
}
void solve ()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++ i)
		cin >> a[i].u >> a[i].v >> a[i].w;
	for (int i = 1; i <= k; ++ i)
	{
		cin >> c[i];
		for (int j = 1; j <= n; ++ j)
			cin >> d[i][j];
	}
	if (k == 0)
	{
		for (int i = 1; i <= n; ++ i)
			f[i] = i;
		sort (a + 1, a + m + 1, [](node a, node b){return a.w < b.w;});
		int cnt = 0;
		i64 ans = 0;
		for (int i = 1; i <= m; ++ i)
		{
			int u = a[i].u, v = a[i].v, fu = Find (u), fv = Find (v);
			if (fu ^ fv)
			{
				++ cnt;
				ans += a[i].w;
				f[fu] = fv;
				if (cnt == n - 1)
					break;
			}
		}
		cout << ans;
		return;
	}
	mm = m;
	nn = n;
	dfs (1, 0);
	cout << res;
}
signed main ()
{
	ios::sync_with_stdio (0);
	cin.tie (0);
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	while (T --)
		solve ();
	return 0;
}
