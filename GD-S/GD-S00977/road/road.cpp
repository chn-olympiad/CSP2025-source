#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
const int N = 1e5 + 2, M = 3e6 + 2;
struct E {
	int u, v, w;
	bool operator< (const E& W) const { return w < W.w; }
} e[M], g[M];
int n, m, k, idx, res, fa[N];
int find(int x) { return x == fa[x] ? x : (fa[x] = find(fa[x])); }
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1, u, v, w; i <= m; i++)
		cin >> u >> v >> w, g[i] = {u, v, w}, e[i] = g[i];
	sort(e + 1, e + m + 1), iota(fa, fa + n + 1, 0);
	for (int i = 1; i <= m; i++) {
		int u = find(e[i].u), v = find(e[i].v), w = e[i].w;
		if (u != v) fa[u] = v, res += w;
	}
	for (int i = 1; i <= k; i++) {
		int c = 0, tot = 0;
		for (int j = 1; j <= m; j++) e[j] = g[j];
		idx = m, cin >> c, e[++idx] = {0, n + 1, c};
		for (int j = 1, x; j <= n && cin >> x; j++)
			e[++idx] = {j, n + 1, x};
		sort(e + 1, e + idx + 1), iota(fa, fa + n + 2, 0);
		for (int j = 1; j <= idx; j++) {
			int u = find(e[j].u), v = find(e[j].v), w = e[j].w;
			if (u != v) fa[u] = v, tot += w;
		}
		res = min(res, tot);
	}
	cout << res << '\n';
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
