#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e4 + 2, M = 1e6 + 2, K = 12;
struct Edge {
	int u, v, w;
} e[M];// es[N];
int n, m, k, fa[N], c[K], a[K][N], vis[M];
int get(int u) {
	return u == fa[u] ? u : fa[u] = get(fa[u]);
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i)
		cin >> e[i].u >> e[i].v >> e[i].w;
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		for (int j = 1; j <= n; ++j)
			cin >> a[i][j];
	}
	sort(e + 1, e + m + 1, [](const Edge& x, const Edge& y){return x.w < y.w;});
	for (int i = 1; i <= n; ++i) fa[i] = i;
	ll ans = 0;
	int idx = 0;
	for (int i = 1; i <= m; ++i) {
		int p = get(e[i].u), q = get(e[i].v);
		if (p != q)
			fa[p] = q, ans += e[i].w;
	}
	if (!k) {
		cout << ans;
		return 0;
	}
	cout << ans;
	return 0;
}
/*
g++ road.cpp -o road -std=c++14 -O2 -static
*/