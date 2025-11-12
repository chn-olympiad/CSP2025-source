#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int, int>> g[10004];
int fa[10004];
int find(int x)
{
	if (fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}
inline void merge(int x, int y)
{
	fa[find(x)] = find(y);
}
vector<tuple<int, int, int>> edge;
int sv[11][10004], c[11], n, m, k;
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	bool a{true};
	cin >> n >> m >> k;
	for (int i{1}; i <= n; i++)
		fa[i] = i;
	while (m--)
	{
		int u, v, w;
		cin >> u >> v >> w;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
		edge.emplace_back(w, u, v);
	}
	if (!k)
	{
		sort(begin(edge), end(edge));
		int tot{};
		for (auto x : edge)
		{
			int u, v, w;
			tie(w, u, v) = x;
//			cout << u << ' ' << v << ' ' << w << endl;
			if (find(u) != find(v))
				tot += w, merge(u, v);
		}
		cout << tot;
		return 0;
	}
	for (int i{1}; i <= k; i++)
	{
		cin >> c[i];
		bool f{};
		for (int j{1}; j <= n; j++)
			if (cin >> sv[i][j], !sv[i][j])
				f = true;
		a &= f & !c[i];
	}
	if (a)
	{
		for (int i{1}; i <= k; i++)
		{
			int res;
			for (int j{1}; j <= n; j++)
				if (!sv[i][j])
				{
					res = j;
					break;
				}
			for (int j{1}; j <= n; j++)
				if (res != j)
					edge.emplace_back(sv[i][j], res, j);
		}
		sort(begin(edge), end(edge));
		int tot{};
		for (auto x : edge)
		{
			int u, v, w;
			tie(w, u, v) = x;
//			cout << u << ' ' << v << ' ' << w << endl;
			if (find(u) != find(v))
				tot += w, merge(u, v);
		}
		cout << tot;
		return 0;
	}
	return 0;
}
