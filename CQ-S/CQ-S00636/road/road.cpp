#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio (0), cin.tie (0), cout.tie (0)
#define res register int
#define int long long
#define rep(i, l, r) for (res i = (l); i <= (r); i ++)
#define drep(i, l, r) for (res i = (r); i >= (l); i --)
#define tim clock () * 1.0 / CLOCKS_PER_SEC
#define PII pair <int, int>
#define iv inline void
#define siz(x) (int)x.size ()
#define all(x) x.begin (), x.end ()
#define pb push_back
using namespace std;
const int N = 1000005, M = 12, inf = 1e18;
iv cmin(int &x, int y) { x = x < y ? x : y; }
int n, m, k, c[N], w[M][N], fa[N], ans = inf;
struct node { int u, v, w; } E[N], e[N], ne[N];
int find (int x) { return fa[x] == x ? x : fa[x] = find (fa[x]); }
iv init () {
	int m2 = m; m = 0;
	sort (E + 1, E + 1 + m2, [&] (node i, node j) { return i.w < j.w; });
	rep(i, 1, n) fa[i] = i;
	rep(i, 1, m2) {
		int u = find (E[i].u), v = find (E[i].v);
		if (u ^ v) fa[u] = v, e[++ m] = E[i];
	}
}
iv calc (int x) {
	rep(i, 1, m) ne[i] = e[i]; int m2 = m, ret = 0;
	rep(i, 1, n + k) fa[i] = i;
	rep(i, 1, k) if (x >> (i - 1) & 1) {
		ret += c[i];
		rep(j, 1, n) ne[++ m2] = {n + i, j, w[i][j]};
	}
	sort (ne + 1, ne + 1 + m2, [&] (node i, node j) { return i.w < j.w; });
	rep(i, 1, m2) {
		int u = find (ne[i].u), v = find (ne[i].v);
		if (u ^ v) fa[u] = v, ret += ne[i].w;
	} cmin(ans, ret);
}
iv solve () {
	cin >> n >> m >> k;
	rep(i, 1, m) cin >> E[i].u >> E[i].v >> E[i].w;
	init ();
	rep(i, 1, k) {
		cin >> c[i];
		rep(j, 1, n) cin >> w[i][j];
	}
	rep(i, 0, (1 << k) - 1) calc (i);
	cout << ans << '\n';
}
signed main () {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	FASTIO;
	int T = 1; //cin >> T;
	while (T --) solve ();
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
