//GZ-S00042 贵阳市第一中学 刘信果
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e4+25, M = 1e6+5, K = 15;
int n, gm, hm, em, k, ed, c[K], a[K][N], sum, ans = LONG_LONG_MAX;
struct Edge {
	int u, v, w;
	friend bool operator <(Edge a, Edge b) {
		return a.w < b.w;
	} 
}g[M], h[N], e[M];

struct Bcj {
	int fa[N];
	void init() {
		for (int i = 1; i <= n+k; ++i)
			fa[i] = i;
	}
	int find(int x) {
		return x == fa[x] ? x : fa[x] = find(fa[x]);
	}
	bool merge(int x, int y) {
		int fx = find(x), fy = find(y);
		if (fx == fy) return 0;
		fa[fx] = fy;
		return 1;
	}
}bcj;

int solve() {
	bcj.init();
	for (int i = 1; i <= em; ++i) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if (bcj.merge(u, v)) sum += w;
	}
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> gm >> k;
	for (int i = 1; i <= gm; ++i)
		cin >> g[i].u >> g[i].v >> g[i].w;
	sort(g+1, g+gm+1);
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		for (int j = 1; j <= n; ++j)
			cin >> a[i][j];
	}
	for (int j = 0; j < (1<<k); ++j) {
		hm = em = sum = 0;
		for (int p = 1; p <= k; ++p) {
			if ((j&(1<<p-1)) == 0) continue;
			for (int i = 1; i <= n; ++i)
				h[++hm] = {n+p, i, a[p][i]};
			sum += c[p]; 
		}
		sort(h+1, h+hm+1);
		int gi = 1, hi = 1;
		while (gi <= gm && hi <= hm) {
			if (g[gi].w < h[hi].w)
				e[++em] = g[gi++];
			else
				e[++em] = h[hi++];
		}
		while (gi <= gm)
			e[++em] = g[gi++];
		while (hi <= hm)
			e[++em] = h[hi++]; 
		sum += solve();
		ans = min(ans, sum);
	}
	cout << ans;
	return 0;
}
