#include <bits/stdc++.h>
using namespace std;
int n, m, k, ans, fa[10005], c[11], a[11][100005];
struct node {
	int u, v, w;
	bool operator < (const node &t) const {
		return w < t.w;
	}
};
vector <node> G;
struct edge {
	int v, w;
};
vector <edge> G1[10005];
int find(int x) {
	return (fa[x] == x ? x : fa[x] = find(fa[x]));
}
void Kruskal() {
	for (int i = 1; i <= n; i++) fa[i] = i;
	sort(G.begin(), G.end());
	int cnt = 0;
	for (int i = 0; i < G.size(); i++) {
		int u = G[i].u, v = G[i].v, w = G[i].w;
		int fu = find(u), fv = find(v);
		if (fu != fv) {
			fa[fu] = fv, cnt++, ans += w;
			G1[u].push_back({v, w}), G1[v].push_back({u, w});
			if (cnt == n - 1) break;
		}
	}
}
void dfs(int x, int sum, vector <node> now) {
	if (x == k + 1) {
		ans = min(ans, sum);
		return ;
	}
	dfs(x + 1, sum, now);
	int s = 0;
	for (int i = 0; i < now.size(); i++) {
		int u = now[i].u, v = now[i].v, w = now[i].w;
		if (u > n || v > n) continue;
		int t = w - (a[x][u] + a[x][v]);
		if (t > 0) s += t, now[i].v = x + n, now[i].w = a[x][u], now.push_back({v, x + n, a[x][v]});
	}
	dfs(x + 1, sum + c[x] - s, now);
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		G.push_back({u, v, w});
	}
	Kruskal();
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) cin >> a[i][j], G.push_back({i + n, j, a[i][j]});
	}
	// dfs(1, ans, G1);
	for (int i = 1; i <= k; i++) {
		if (G1[i + n].size() > 1) ans += c[i];
		else if (G1[i + n].size() == 1) ans -= G1[i + n][0].w; 
	}
	cout << ans << "\n";
	return 0;
}
