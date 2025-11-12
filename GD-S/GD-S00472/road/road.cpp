#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int read() {
	int x = 0, ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
	return x;
}

namespace DSU {
	int fa[10015];
	void init(int _n) { iota(fa + 1, fa + _n + 1, 1); }
	int find(int x) { while (x != fa[x]) x = fa[x] = fa[fa[x]]; return fa[x]; }
}

struct edge { int u, v, w; } e[1000005], rel[10005], rp[15][10005], al[150005];

int n, m, k, tot, g[15], f[110005];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (int i = 1; i <= m; i++) e[i].u = read(), e[i].v = read(), e[i].w = read();
	for (int i = 1; i <= k; i++) {
		g[i] = read();
		for (int j = 1; j <= n; j++) rp[i][j].w = read(), rp[i][j].u = i + n, rp[i][j].v = j;
	}
	sort(e + 1, e + m + 1, [](edge x, edge y) { return x.w < y.w; });
	DSU::init(n);
	for (int i = 1; i <= m; i++) {
		int uu = DSU::find(e[i].u), vv = DSU::find(e[i].v);
		if (uu != vv) {
			rel[++tot] = e[i], DSU::fa[uu] = vv;
			if (tot == n - 1) break;
		}
	} tot = 0;
	for (int i = 1; i < n; i++) al[++tot] = rel[i];
	for (int i = 1; i <= k; i++) for (int j = 1; j <= n; j++) al[++tot] = rp[i][j];
	sort(al + 1, al + tot + 1, [](edge x, edge y) { return x.w < y.w; });
	for (int i = 1; i <= tot; i++) f[i] = max(al[i].u, al[i].v);
	LL res = 0x3f3f3f3f3f3f3f3fLL;
	for (int S = 0; S < (1 << k); S++) {
		LL ans = 0; int ts = 0;
		for (int i = 1; i <= k; i++) if ((S >> (i - 1)) & 1) ans += g[i];
		DSU::init(n + k);
		for (int i = 1, uu, vv; i <= tot; i++) if (f[i] <= n || ((S >> (f[i] - n - 1)) & 1)) {
			uu = DSU::find(al[i].u), vv = DSU::find(al[i].v);
			if (uu != vv) { DSU::fa[uu] = vv, ans += al[i].w; if ((++ts) == n + __builtin_popcount(S) - 1) break; }
		}
		res = min(res, ans);
	}
	return printf("%lld\n", res), 0;
}
