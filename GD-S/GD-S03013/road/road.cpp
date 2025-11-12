#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// #define int ll

 #define SUBMIT

constexpr int maxn = 10010 * 4, maxm = 1000010 * 4, maxk = 10 * 4;

int c[maxk];

struct Edge {
	int u, v, w, is_in, depends;
	constexpr bool operator<(const Edge &oth) const {
		return w < oth.w;
	}
} edges[maxm];

int cnt_edge = 0;

inline void add(int u, int v, int w, int depends) {
	edges[++cnt_edge] = { u, v, w, false, depends };
}

int n, m, k;

int fa[maxn], sz[maxn];

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

ll kruskal(int act) {
	ll rtn = 0LL;
	for (int i = 1; i <= n + k; ++i)
		fa[i] = i, sz[i] = 1;
	for (int edge = 1; edge <= cnt_edge; ++edge) {
		const int u = edges[edge].u, v = edges[edge].v, w = edges[edge].w;
		const int depends = edges[edge].depends;
		if (depends && !(act >> (depends - 1) & 1))
			continue;
		int fu = find(u), fv = find(v);
		if (fu == fv)
			continue;
		rtn += w;
		if (sz[fu] < sz[fv])
			swap(fu, fv);
//		 << u << ' ' << v << ' ' << w << ' ' << '\n';
		fa[fu] = fa[fv];
		edges[edge].is_in = true;
	}
	
//	for (int i = 1; i <= n; ++i)
//		assert(find(i) == find(1));
	
	return rtn;
}

signed main() {
#ifdef SUBMIT
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("road.in", "r", stdin); freopen("road.out", "w", stdout);
//	freopen("road4.in", "r", stdin); freopen("road4.out", "w", stdout);
#endif

	cin >> n >> m >> k;
	for (int i = 1, u , v, w; i <= m; ++i) {
		cin >> u >> v >> w;
		add(u, v, w, 0);
	}
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		for (int j = 1; j <= n; ++j) {
			int a;
			cin >> a;
			add(n + i, j, a, i);
		}
	}

	sort(edges + 1, edges + cnt_edge + 1);
	ll ans = kruskal(0);
	
	int new_cnt = 0;
	for (int i = 1; i <= cnt_edge; ++i) {
		// 504898585
		if (edges[i].is_in || edges[i].depends) {
			edges[++new_cnt] = edges[i];
		}
	}
	cnt_edge = new_cnt;

	const int max_iter = (1 << k);
	for (int cur_iter = 0; cur_iter < max_iter; ++cur_iter) {
		ll cont = kruskal(cur_iter);
//		cout << cont << '\n';
		for (int j = 1; j <= k; ++j)
			if (cur_iter >> (j - 1) & 1)
				cont += c[j];
//		cout << cont << ' ' << cur_iter << '\n';
		ans = min(ans, cont);
	}

	cout << ans << '\n';

	return 0;
}
