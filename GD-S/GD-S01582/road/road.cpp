#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int N = 1e4 + 25, K = 15;

int n, m, k;
array<array<int, N>, K> a;
array<int, K> c;

class Union_Find
{
public:
	array<int, N> fa, sz;
	inline void Init()
	{
		for (int i = 1; i <= n + k; i++) fa[i] = i, sz[i] = 1;
	}
	inline int find(int u)
	{
		return (fa[u] == u ? u : fa[u] = find(fa[u]));
	}
	inline void merge(int u, int v)
	{
		u = find(u), v = find(v);
		if (sz[u] < sz[v]) swap(u, v);
		fa[v] = u, sz[u] += sz[v];
	}
}uf;

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> k;
	uf.Init();
	vector<tuple<int, int, int>> vt;
	vector<tuple<int, int, int>> rt;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		vt.emplace_back(w, u, v);
	}
	sort(vt.begin(), vt.end());
	ll sum = 0;
	for (int i = 0; i < vt.size(); i++)
	{
		int w = get<0>(vt[i]), u = get<1>(vt[i]), v = get<2>(vt[i]);
		if (uf.find(u) != uf.find(v))
		{
			rt.emplace_back(w, u, v);
			uf.merge(u, v);
			sum += w;
		}
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for (int j = 1; j <= n; j++) cin >> a[i][j], rt.emplace_back(a[i][j], n + i, j);
	}
	sort(rt.begin(), rt.end());
	ll ans = sum;
	for (int i = 1; i < (1 << k); i++)
	{
		ll ns = 0;
		for (int x = 0; x < k; x++)
		{
			if ((i >> x) & 1) ns += c[x + 1];
		}
		uf.Init();
		for (int j = 0; j < rt.size(); j++)
		{
			int w = get<0>(rt[j]), u = get<1>(rt[j]), v = get<2>(rt[j]);
			if (u > n && !((i >> (u - n - 1)) & 1)) continue;
			if (uf.find(u) == uf.find(v)) continue;
			ns += w, uf.merge(u, v);
			if (ns >= ans) break;
		}
		ans = min(ans, ns);
	}
	cout << ans << "\n";
	return 0;
}
