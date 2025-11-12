#include <bits/stdc++.h>
#define int long long
using namespace std;
struct UnFind{
	int n;
	vector <int> f;
	UnFind(int n_) : n(n_) {
		f.assign(n + 1, 0);
		for (int i = 1; i <= n; i ++)
			f[i] = i;
	}
	int find(int x) {
		return f[x] == x ? f[x] : f[x] = find(f[x]);
	}
	void merge(int x, int y) {
		x = find(x), y = find(y);
		f[x] = y;
	}
	bool query(int x, int y) {
		return find(x) == find(y);
	}
};
struct Edge{
	int u, v, w;
};
int getid(int n, int m, int k, vector <Edge>& edge, vector <vector <int>>& c) {
	if (k == 0)
		return 4;
	bool isA = 1;
	for (int j = 1; j <= k; j ++)
		if (c[j][0] != 0)
			isA = 0;
	if (isA)
		return 18;
	return 25;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	vector <Edge> edge(m + 1);
	for (int i = 1; i <= m; i ++)
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
	vector <vector <int>> c(k + 1, vector <int> (n + 1));
	for (int j = 1; j <= k; j ++)
		for (int i = 0; i <= n; i ++)
			cin >> c[j][i];
	int id = getid(n, m, k, edge, c);
	if (id == 4) {
		sort(edge.begin() + 1, edge.begin() + m + 1, [&](Edge x, Edge y) {
			return x.w < y.w;
		});
		UnFind uf(n);
		int ans = 0, cnt = 0;
		for (int i = 1; i <= m; i ++) {
			if (!uf.query(edge[i].u, edge[i].v)) {
				ans += edge[i].w;
				uf.merge(edge[i].u, edge[i].v);
				cnt ++;
			}
		}
		cout << ans << "\n";
		return 0;
	}
	if (id == 18) {
		for (int j = 1; j <= k; j ++)
			for (int i = 1; i <= n; i ++)
				edge.push_back({n + j, i, c[j][i]});
		m += k * n;
		n += k;
		sort(edge.begin() + 1, edge.begin() + m + 1, [&](Edge x, Edge y) {
			return x.w < y.w;
		});
		UnFind uf(n);
		int ans = 0, cnt = 0;
		for (int i = 1; i <= m; i ++) {
			if (!uf.query(edge[i].u, edge[i].v)) {
				ans += edge[i].w;
				uf.merge(edge[i].u, edge[i].v);
				cnt ++;
			}
		}
		cout << ans << "\n";
		return 0;
	}
	return 0;
}
