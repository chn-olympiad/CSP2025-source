#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lowbit(x) ((x) & -(x))
const int M = 1e6 + 5;
const int N = 1e4 + 15;
int n, m, k, f[N], sz[N], a[N], ppc[N], lg[N];
ll sa[N];
struct edge {
	int u, v, w;
} e[M], e1[N * 3], ek[15][N], dp[(1 << 10) + 2][N];
int find(int x) {
	if (x != f[x]) f[x] = find(f[x]);
	return f[x];
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) f[i] = i, sz[i] = 1;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[i] = {u, v, w};
	}
	for (int i = 1; i <= k; i++) {
		cin >> a[i];
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			ek[i][j] = {i + n, j, x};
		}
		sort(ek[i] + 1, ek[i] + n + 1, [](edge a1, edge b1){
			return a1.w < b1.w;
		});
	}
	int m1 = 0;
	sort(e + 1, e + 1 + m, [](edge a1, edge b1){
		return a1.w < b1.w;
	});
	ll ans = 1e18;
	ll sum = 0;
	for (int i = 1; i <= m; i++) {
		int u = e[i].u, v = e[i].v;
		int fx = find(u), fy = find(v);
		if (fx == fy) continue;
		if (sz[fx] > sz[fy]) swap(fx, fy);
		f[fx] = fy, sz[fy] += sz[fx];
		dp[0][++m1] = e[i];
		sum += e[i].w;
	}
	ans = min(ans, sum);
	for (int i = 2; i < N; i++) lg[i] = lg[i >> 1] + 1;
	for (int s = 1; s < (1 << k); s++) {
		int tmp = s - lowbit(s);
		int t = lg[lowbit(s)] + 1;
		sa[s] = sa[tmp] + a[t];
		int tt = 0;
		int x = 1, y = 1;
		int sz1 = (int)__builtin_popcount(s - lowbit(s)) + n - 1, sz2 = n;
		for (int i = 1; i <= n + k; i++) f[i] = i, sz[i] = 1;
		int m1 = 0;
		ll sum = 0;
		while (x <= sz1 || y <= sz2) {
			if (x > sz1) {
				e1[++tt] = (ek[t][y++]);
			} else if (y > sz2) {
				e1[++tt] = (dp[tmp][x++]);
			} else if (dp[tmp][x].w <= ek[t][y].w) {
				e1[++tt] = (dp[tmp][x++]);
			} else e1[++tt] = (ek[t][y++]);
			edge ed = e1[tt];
			int u = ed.u, v = ed.v;
			int fx = find(u), fy = find(v);
			if (fx == fy) continue;
			if (sz[fx] > sz[fy]) swap(fx, fy);
			f[fx] = fy, sz[fy] += sz[fx];
			dp[s][++m1] = ed;
			sum += ed.w;
		}
		ans = min(ans, sum + sa[s]);
	}
	cout << ans;
	return 0;
}

