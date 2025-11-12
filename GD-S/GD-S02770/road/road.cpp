#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
constexpr int N = 1e4 + 10, M = 1e6;
int n, m, k, cnt;
struct edge {
	int u, v, w;
	constexpr bool operator <(const edge &x) const {
		return w < x.w;
	}
} e[M + 5], st[N + 5];
int c[11], a[11][N + 5];
struct DSU {
	int fa[N + 5], sz[N + 5];
	void init(int n) {
		for (int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1;
	}
	int find(int u) {
		return u == fa[u] ? u : fa[u] = find(fa[u]);
	}
	bool uni(int u, int v) {
		u = find(u), v = find(v);
		if (u == v) return false;
		if (sz[u] > sz[v]) swap(u, v);
		fa[u] = v, sz[v] += sz[u];
		return true;
	}
} dsu;
bool vis[11];
template<typename T>
void read(T &x) {
	static_assert(is_integral<T>());
	x = 0;
	int ch = getchar();
	while (ch < 48 || ch > 57) ch = getchar();
	while (ch >= 48 && ch <= 57) {
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
}
LL solve(int x) {
	LL ret = 0;
	memcpy(e + 1, st + 1, sizeof(edge) * (n - 1));
	cnt = n - 1;
	for (int i = 1; i <= k; i++)
		if (x >> i - 1 & 1) {
			ret += c[i];
			for (int j = 1; j <= n; j++)
				e[++cnt] = {n + i, j, a[i][j]};
		}
	sort(e + 1, e + cnt + 1);
	dsu.init(n + k);
	for (int i = 1; i <= cnt; i++) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		ret += dsu.uni(u, v) * w;
	}
	return ret;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n), read(m), read(k);
	for (int _ = 1; _ <= m; _++) {
		int u, v, w;
		read(u), read(v), read(w);
		e[++cnt] = {u, v, w};
	}
	sort(e + 1, e + m + 1);
	dsu.init(n);
	LL ans = 0;
	cnt = 0;
	for (int i = 1; i <= m; i++) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if (dsu.uni(u, v)) {
			st[++cnt] = {u, v, w};
			ans += w;
		}
	}
	for (int i = 1; i <= k; i++) {
		read(c[i]);
		for (int j = 1; j <= n; j++) read(a[i][j]);
	}
	for (int i = 1; i < 1 << k; i++)
		ans = min(ans, solve(i));
	printf("%lld\n", ans);
	return 0;
}

