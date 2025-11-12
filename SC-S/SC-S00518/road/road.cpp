#include <bits/stdc++.h>
using ll = long long;
using std::cin;
using std::cout;
using std::cerr;
using std::min;
using std::max;
using std::swap;

const int MAXN = 1e4 + 5, MAXM = 1e6 + 5, MAXK = 11;
int n, m, k;
int c[MAXK], a[MAXK][MAXN];
struct Edge {
	int u, v;
	ll w;
	bool operator < (const Edge &oth) const {
		return w < oth.w;
	}
} e[MAXM], e1[MAXN + 1000 * 500 * MAXK];
int cnt;
struct UnionFind {
	int fa[MAXN];
	UnionFind() {
		for (int i = 0; i <= n; ++i) fa[i] = i;
	}
	int Find(int x) { return (x == fa[x] ? x : fa[x] = Find(fa[x])); }
	bool Merge(int x, int y) {
		if (x == y) return false;
		x = Find(x), y = Find(y);
		if (x == y) return false;
		fa[y] = x;
		return true;
	}
};
ll ans = 0;
ll maxw;
void Kruskal() {
	std::sort(e + 1, e + m + 1);
	ans = 0;
	UnionFind U;
	int tot = 0;
	for (int i = 1; i <= m; ++i) {
		int u = e[i].u, v = e[i].v; ll w = e[i].w;
		if (U.Merge(u, v)) {
			++tot;
			e1[++cnt] = {u, v, w};
			ans += w;
			if (tot == n - 1) {
				maxw = w;
				break;
			}
		}
	}
}

void Kruskal2() {
	std::sort(e1 + 1, e1 + cnt + 1);
	ans = 0;
	UnionFind U;
	int tot = 0;
	for (int i = 1; i <= cnt; ++i) {
		int u = e1[i].u, v = e1[i].v; ll w = e1[i].w;
		if (U.Merge(u, v)) {
			++tot;
			ans += w;
			if (tot == n - 1) 
				break;
		}
	}
}
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1, u, v; i <= m; ++i) {
		ll w;
		cin >> u >> v >> w;
		e[i] = {u, v, w};
	}
	Kruskal();
	if (k == 0) {
		cout << ans;
		return 0;
	}
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		for (int j = 1; j <= n; ++j) cin >> a[i][j];
	}
	for (int u = 1; u <= n; ++u) {
		for (int v = 1; v < u; ++v) {
			for (int i = 1; i <= k; ++i) {
				if (0ll + c[i] + a[i][u] + a[i][v] >= maxw) continue;
				e1[++cnt] = {u, v, 0ll + c[i] + a[i][u] + a[i][v]};
			}
		}
	}
	if (cnt != n - 1) Kruskal2();
	cout << ans;
	return 0;
}