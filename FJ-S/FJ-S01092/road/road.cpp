#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int read() {
	int res = 0, flag = 1, c = getchar();
	while (!isdigit(c)) {
		if (c == '-') flag = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res * flag;
}

const int N = 20010, M = 2000010, K = 15;
int n, m, k, c[K], a[K][N];

struct Edge {
	int a, b, c; 
	bool operator < (const Edge &t) const {
		return c < t.c;
	}
} edges[M], g[M]; 

struct DSU {
	int fa[N], sz[N];
	void init(int n) {
		for (int i = 1; i <= n; i ++) fa[i] = i, sz[i] = 1;
	}
	int find(int x) {
		if (fa[x] == x) return x;
		return fa[x] = find(fa[x]);
	}
	void merge(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return;
		if (sz[x] < sz[y]) swap(x, y);
		sz[x] += sz[y], fa[y] = x;
	}
} dsu;

LL Kruskal(int n, int m) {
	dsu.init(n); 
	sort(g + 1, g + 1 + m);
	LL res = 0;
	for (int i = 1; i <= m; i ++) {
		int x = g[i].a, y = g[i].b, z = g[i].c;
		if (dsu.find(x) == dsu.find(y)) continue;
		res += z; dsu.merge(x, y);
	}
	if (dsu.sz[dsu.find(1)] != n) return 1e16;
	return res;
}

namespace Subtask2 {
	bool check() {
		for (int i = 1; i <= k; i ++) {
			if (c[i]) return false;
			bool flag = false;
			for (int j = 1; j <= n; j ++)
				if (!a[i][j]) flag = true;
			if (!flag) return false;
		}
		return true;
	}
	void main() {
		for (int i = 1; i <= k; i ++) {
			int p = 0;
			for (int j = 1; j <= n; j ++) if (!a[i][j]) p = j;
			for (int j = 1; j <= n; j ++) if (j != p) 
				edges[++ m] = {p, j, a[i][j]};
		}
		sort(edges + 1, edges + 1 + m); 
		dsu.init(n); LL res = 0;
		for (int i = 1; i <= m; i ++) {
			int a = edges[i].a, b = edges[i].b, c = edges[i].c;
			if (dsu.find(a) == dsu.find(b)) continue;
			res += c; dsu.merge(a, b);
		}
		printf("%lld\n", res);
	}
};

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (int i = 1; i <= m; i ++) {
		int a = read(), b = read(), c = read();
		edges[i] = {a, b, c};
	}
	for (int i = 1; i <= k; i ++) {
		c[i] = read();
		for (int j = 1; j <= n; j ++) a[i][j] = read();
	}
	if (Subtask2::check()) {
		Subtask2::main();
		return 0;
	}
	LL ans = 1e16;
	for (int i = 0; i < (1 << k); i ++) {
		for (int j = 1; j <= m; j ++) g[j] = edges[j];
		int totm = m, totn = n; LL res = 0;
		for (int j = 1; j <= k; j ++)
			if (i >> (j - 1) & 1) {
				totn ++; res += c[j]; 
				for (int t = 1; t <= n; t ++) 
					g[++ totm] = {n + j, t, a[j][t]};
			}
		res += Kruskal(totn, totm); ans = min(ans, res);
	}
	printf("%lld\n", ans);
	return 0;
}
