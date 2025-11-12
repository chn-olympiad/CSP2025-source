#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 10009, M = 2000009, K = 12;
struct edge {
	int u, v, w;
}e[M];
bool cmp(edge a, edge b) {
	return a.w < b.w;
}
int n, m, k, c[K], a[K][N], txa, ans;
int fa[N], sz[N];
int anc(int x) { return fa[x] == x ? x : fa[x] = anc(fa[x]); }
bool mer(int x, int y) { 
	if ((x = anc(x)) == (y = anc(y))) return 0;
	if (sz[x] < sz[y]) swap(x, y);
	fa[y] = x, sz[x] += sz[y];
	return 1;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	txa = 1;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) cin >> e[i].u >> e[i].v >> e[i].w;
	for (int i = 1; i <= k; i++) {
		cin >> c[i], txa &= (c[i] == 0);
		for (int j = 1; j <= n; j++) cin >> a[i][j];
	}
	if (k == 0) {
		for (int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1;
		sort(e + 1, e + m + 1, cmp);
		for (int i = 1; i <= m; i++) 
			if (mer(e[i].u, e[i].v))
				ans += e[i].w;
		cout << ans;
		exit(0);
	}
	if (txa) {
		for (int i = 1; i <= k; i++) {
			for (int j = 1; j <= n; j++) e[++m] = {n + i, j, a[i][j]};
		}
		n += k;
		for (int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1;
		sort(e + 1, e + m + 1, cmp);
		for (int i = 1; i <= m; i++) 
			if (mer(e[i].u, e[i].v))
				ans += e[i].w;
		cout << ans;
		exit(0);
	}
}//48??