#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1 << 30;

const int N = 1e4 + 3;
const int M = 1e6 + 3;

struct info {
	int u, v, w;
	bool operator < (const info &A) const {
		return w < A.w;
	}
} a[M], t[M + 10 * N];

int c[N], f[N], cost[11][N];

int gf (int i) {
	return i == f[i] ? i : f[i] = gf(f[i]);
}

int n, m, k;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf ("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf ("%d%d%d", &u, &v, &w);
		a[i] = (info){u, v, w};
	}
	int _t = inf;
	for (int i = 0; i < k; i++) {
		scanf ("%d", &c[i]);
		int _r = c[i];
		for (int j = 1; j <= n; j++) scanf ("%d", &cost[i][j]);
		for (int j = 1; j <= n; j++) _r = max(_r, cost[i][j]);
		_t = min(_t, _r);
	}
	if (!_t) {
		printf("0\n");
		return 0;
	}
	sort(a + 1, a + m + 1);
	for (int i = 1; i <= n; i++) f[i] = i;
	int nm = 0;
	ll ans = 0;
	for (int i = 1; i <= m; i++) {
		int u = a[i].u, v = a[i].v, w = a[i].w;
		if (gf(u) != gf(v)) {
			f[gf(u)] = gf(v);
			ans += 1ll * w;
			a[++nm] = a[i];
		}
	}
	m = nm;
	for (int S = 0; S < 1 << k; S++) {
		ll res = 0;
		int len = 0, cnt= n;
		for (int i = 0; i < k; i++) if (S & 1 << i) {
			res += 1ll * c[i]; ++cnt;
			for (int j = 1; j <= n; j++) t[++len] = (info){cnt, j, cost[i][j]};
		}
		for (int i = 1; i <= m; i++) t[++len] = a[i];
		sort(t + 1, t + len + 1);
		for (int i = 1; i <= cnt; i++) f[i] = i;
		for (int i = 1; i <= len; i++) {
			int u = t[i].u, v = t[i].v, w = t[i].w;
			if (gf(u) != gf(v)) {
				f[gf(u)] = gf(v);
				res += 1ll * w;
			}
		}
		ans = min(ans, res);
	}
	printf("%lld\n", ans);
}
