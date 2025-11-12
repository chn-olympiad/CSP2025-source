#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
using ldb = long double;

const int N = 1e4 + 5, M = 1e6 + 5, K = 1 << 10;
int n, m, k, c[K], a[K][N], cnt, ce[K];
ll res;
struct edge {
	int u, v, w;
	friend bool operator < (edge x, edge y) {
		return x.w < y.w;
	}
} be[M], g[K][N], e[K][N];

struct Dsu {
	int fa[N], siz[N];
	inline void init(int n) {
		for (int i = 1; i <= n; ++i) {
			fa[i] = i;
			siz[i] = 1;
		}
	}
	inline int find(int x) {
		return fa[x] == x ? x : fa[x] = find(fa[x]);
	}
	inline void merge(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return;
		if (siz[x] > siz[y]) swap(x, y);
		fa[x] = y;
		siz[y] += siz[x];
	}
	inline int operator [](int x) { return find(x); }
} dsu;

inline ll get_tree(int n, int m1, edge e1[], int m2, edge e2[], int &m, edge e3[]) {
	int b1 = 1, b2 = 1;
	ll res = 0;
	m = 0;
	dsu.init(n);
	while (b1 <= m1 || b2 <= m2) {
		int u, v, w, id;
		if ((b1 <= m1 && b2 <= m2 && e1[b1].w <= e2[b2].w) || b2 > m2) {
			u = e1[b1].u, v = e1[b1].v, w = e1[b1].w;
			++b1;
			id = 1;
		} else {
			u = e2[b2].u, v = e2[b2].v, w = e2[b2].w;
			++b2;
			id = 2;
		}
		u = dsu[u], v = dsu[v];
		if (u == v) continue;
		if (id == 1) e3[++m] = e1[b1 - 1];
		else e3[++m] = e2[b2 - 1];
		dsu.merge(u, v);
		res += w;
	}
	return res;
}

#define lowbit(x) ((x) & -(x))

int main() {
//	cerr << 1.0 * (sizeof (be) + sizeof (g) + sizeof (e)) / 1024 / 1024;
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i)
		cin >> be[i].u >> be[i].v >> be[i].w;
	sort(be + 1, be + m + 1);
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		cnt = 0;
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			e[i][++cnt] = edge { n + i, j, a[i][j] };
		}
		sort(e[i] + 1, e[i] + cnt + 1);
	}
	res = get_tree(n, m, be, 0, new edge[1], ce[0], g[0]);
	for (int S = 1; S < (1 << k); ++S) {
		int ps = S ^ lowbit(S), id = __lg(lowbit(S)) + 1;
		ll cos = 0;
		for (int i = 1; i <= k; ++i)
			if (S & (1 << (i - 1)))
				cos += c[i];
//		cerr << S << ' ' << cos + get_tree(n + k, ce[ps], g[ps], n, e[id], ce[S], g[S]) << '\n';
		res = min(res, cos + 
			get_tree(n + k, ce[ps], g[ps], n, e[id], ce[S], g[S]));
	}
	cout << res;
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
