#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int _ = 1e4 + 10;
const int M = 1e6 + 10;
ll c[_][_], fa[_];
struct intention
{
	int u, v;
	ll w;
}road[M];
bool cmp(intention a, intention b)
{
	return a.w < b.w;
}
int find(int a)
{
	if (fa[a] == a)
		return a;
	fa[a] = find(fa[a]);
}
void merge(int a, int b)
{
	fa[a] = find(b);
}
void solve();
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	solve();
	return 0;
}
void solve()
{
	ll n, m, k;
	ll ans = 0, cnt = 0;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++)
	{
		ll u, v, w;
		cin >> u >> v >> w;
		road[i].u = u, road[i].v = v, road[i].w = w;
	}
	sort(road + 1, road + m + 1, cmp);
	for (int i = 1; i <= k; i++)
	{
		cin >> c[i][0];
		for (int j = 1; j <= n; j++)
			cin >> c[i][j];
	}
	for (int i = 1; i <= m; i++)
	{
		if (find(road[i].u) == find(road[i].v))
			continue;
		ans += road[i].w;
		merge(road[i].u, road[i].v);
		cnt++;
		if (cnt == n - 1)
			break;
	}
	if (k == 0)
		cout << ans << '\n';
	else
		cout << 0 << '\n';
}

