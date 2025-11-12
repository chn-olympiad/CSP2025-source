#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = (int)1e4 + 25;
const int M = (int)1e6 + 5;
const ll inf = (ll)1e18;

int T, n, m, k, tot;
ll co[15];

struct E {
	int u, v;
	ll w;

	E (int u = 0, int v = 0, ll w = 0):
		u(u), v(v), w(w) {}
} a[M], b[1024][N], c[15][N], d[N * 2];

int fa[N];

int find(int u) {
	return fa[u] == u ? u : fa[u] = find(fa[u]);
}

bool cmp(E x, E y) {
	return x.w < y.w;
}

ll ans;

void work(int cid) {
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	sort(a + 1, a + m + 1, cmp);
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	ans = 0;
	for (int i = 1; i <= m; i++) {
		int u = find(a[i].u), v = find(a[i].v);
		if (u == v) {
			continue;
		}
		fa[u] = v;
		b[0][++tot] = a[i];
		ans += a[i].w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> co[i];
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			c[i][j] = E(n + i, j, x);
		}
		sort(c[i] + 1, c[i] + n + 1, cmp);
	}
	sort(b[0] + 1, b[0] + tot + 1, cmp);
	for (int s = 1; s < 1 << k; s++) {
		int cnt = __builtin_popcount(s) + n;
		int lb = s & -s;
		int ib = 32 - __builtin_clz(lb);
		int ns = s ^ lb;
		int tot = 0;
		for (int i = 1, j = 1; i <= cnt - 2 || j <= n; ) {
			if (j > n || (i <= cnt - 1 && b[ns][i].w <= c[ib][j].w)) {
				d[++tot] = b[ns][i++];
			} else {
				d[++tot] = c[ib][j++];
			}
		}
		for (int i = 1; i <= n + k; i++) {
			fa[i] = i;
		}
		ll sum = 0;
		for (int i = 1; i <= k; i++) {
			if (s >> i - 1 & 1) {
				sum += co[i];
			}
		}
		int nn = 0;
		for (int i = 1; i <= tot; i++) {
			int u = find(d[i].u), v = find(d[i].v);
			if (u == v) {
				continue;
			}
			fa[u] = v;
			sum += d[i].w;
			b[s][++nn] = d[i];
		}
		ans = min(ans, sum);
	}
	cout << ans << '\n';
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	T = 1;
	for (int cid = 1; cid <= T; cid++) {
		work(cid);
	}

	return 0;
}