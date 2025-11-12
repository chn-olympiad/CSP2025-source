#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 5, M = 1e6 + 5, K = 12, inf = 1e18;
int n, m, k, idx, c[K], a[K][N], ans = inf;
struct edge { int x, y, w; } e[M], f[M], g[M];

struct disjoint_set_union {
	int p[N], dep[N];
	
	void init(int n) {
		for(int i = 1; i <= n; i ++) { p[i] = i, dep[i] = 1; }
	}
	int find(int x) { return (x == p[x] ? x : p[x] = find(p[x])); }
	bool same(int x, int y) { return (find(x) == find(y)); }
	int merge(int x, int y) {
		x = find(x), y = find(y);
		if(x == y) { return x; }
		if(dep[x] > dep[y]) { swap(x, y); }
		return dep[y] = max(dep[y], dep[x] + 1), p[x] = y, y;
	}
} dsu;

void solve() {
	cin >> n >> m >> k;
	for(int i = 1, x, y, w; i <= m; i ++) {
		cin >> x >> y >> w, e[i] = {x, y, w};
	}
	sort(e + 1, e + 1 + m, [](const edge& x, const edge& y) {
		return x.w < y.w;	
	});
	dsu.init(n);
	for(int i = 1; i <= m; i ++) {
		int x = e[i].x, y = e[i].y, w = e[i].w;
		if(!dsu.same(x, y)) {
			dsu.merge(x, y), f[++ idx] = {x, y, w};
		}
	}
	for(int i = 1; i <= k; i ++) {
		cin >> c[i];
		for(int j = 1; j <= n; j ++) { cin >> a[i][j]; }
	}
	for(int s = 0, res = 0, cnt = 0; s < (1 << k); s ++) {
		idx = res = cnt = 0;
		for(int i = 1; i < n; i ++) { g[++ idx] = f[i]; }
		for(int i = 1; i <= k; i ++) {
			if(s & (1 << (i - 1))) {
				res += c[i], cnt ++;
				for(int j = 1; j <= n; j ++) {
					g[++ idx] = {cnt + n, j, a[i][j]};
				}
			}
		}
		sort(g + 1, g + 1 + idx, [](const edge& x, const edge& y) {
			return x.w < y.w;
		});
		dsu.init(n + cnt);
		for(int i = 1; i <= idx; i ++) {
			int x = g[i].x, y = g[i].y, w = g[i].w;
			if(!dsu.same(x, y)) { 
				dsu.merge(x, y), res += w;
				if(res >= ans) { break; }
			}
		}
		ans = min(ans, res);
	}
	cout << ans << endl;
}
void init() {

}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int cas = 1; // cin >> cas;
	for(; cas --; ) { init(), solve(); }
	return 0;
}

