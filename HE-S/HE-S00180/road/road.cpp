#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 1e6 + 10, M = 11;

int n, m, k, mx;
int c[M], dis[M][M];
int fa[N];
struct zx { int u, v, w; } a[N], b[N], d[N];

bool cmp (zx a, zx b) {
	return a.w < b.w;
}

int find (int x) {
	return x == fa[x] ? x : fa[x] = find (fa[x]);
}

signed main () {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) fa[i] = i;
	for (int i = 1; i <= m; ++i) 
		cin >> a[i].u >> a[i].v >> a[i].w;
	for (int i = 1; i <= k; ++i) {
		cin >> c[i], mx = max (mx, c[i]);
		for (int j = 1; j <= n; ++j) cin >> dis[i][j], mx = max (mx, dis[i][j]);
	}
	sort (a + 1, a + m + 1, cmp);
	int sum = 0, ans = 0;
	for (int i = 1; i <= m; ++i) {
		if (sum == n - 1) break;
		int u = a[i].u, v = a[i].v, w = a[i].w;
		int fu = find (u), fv = find (v);
		if (fu == fv) continue;
		sum++, ans += w, fa[fu] = fv;
		b[sum] = (zx){u, v, w};
	}
	if (!k) {
		cout << ans;
		return 0;
	}
	if (mx == 0) {
		cout << 0;
		return 0;
	}
	for (int s = 0; s < (1 << k); ++s) {
		int sum = 0, tot = 0, cnt = n; m = 0;
		for (int i = 1; i <= k; ++i) if ((s >> (i - 1)) & 1) {
			sum += c[i], cnt++;
			for (int j = 1; j <= n; ++j) d[++tot] = (zx){cnt, j, dis[i][j]};
		}
		for (int i = 1; i < n; ++i) d[++tot] = b[i];
		for (int i = 1; i <= cnt; ++i) fa[i] = i;
		sort (d + 1, d + tot + 1, cmp);
		for (int i = 1; i <= tot; ++i) {
			if (m == cnt - 1) break;
			int u = d[i].u, v = d[i].v, w = d[i].w;
			int fu = find (u), fv = find (v);
			if (fu == fv) continue;
			m++, sum += w, fa[fu] = fv;
		} 
		ans = min (ans, sum);
	} cout << ans;
	return 0;
}
