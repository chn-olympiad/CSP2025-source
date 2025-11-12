#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 5, M = 1e6 + 5;
struct edge{
	int u, v, w;
	bool operator < (const edge &b) const{
		return w < b.w;
	}
}e[M], g[15 * N], orig[N]; 
bitset<M> bk;
int f[N], n, k, m, a[15][N], c[15], tot, head[N];
int getf(int u){ return (f[u] == u ? u : f[u] = getf(f[u])); }
void init(){ for(int i = 1; i <= n + k; ++i) f[i] = i; }
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; ++i){
		int u, v, w; cin >> u >> v >> w;
		e[i] = {u, v, w};
	}
	for(int i = 1; i <= k; ++i){
		cin >> c[i];
		for(int j = 1; j <= n; ++j)
			cin >> a[i][j];
	}
	sort(e + 1, e + 1 + m);
	init();
	tot = 0;
	int ans = 0;
	for(int i = 1; i <= m; ++i){
		int u = e[i].u, v = e[i].v, w = e[i].w;
		u = getf(u), v = getf(v);
		if(u == v) continue;
		++tot, ans += w;
		f[u] = v, bk[i] = 1;
		if(tot == n - 1) break;
	}
	tot = 0;
	int mx = 0;
	for(int i = 1; i <= m; ++i) if(bk[i]) orig[++tot] = {e[i].u, e[i].v, e[i].w}, mx = max(mx, e[i].w);
	for(int s = 1; s < (1 << k); ++s){
		int cost = 0, siz = 0;
		tot = 0;
		for(int i = 1; i < n; ++i) g[++tot] = orig[i];
		init();
		for(int i = 1; i <= k; ++i){
			if(s & (1 << (i - 1))){
				cost += c[i];
				++siz;
				for(int j = 1; j <= n; ++j){
					if(a[i][j] > mx) continue;
					g[++tot] = {n + i, j, a[i][j]};
				}
			}
		}
		sort(g + 1, g + 1 + tot);
		int cnt = 0, nwmx = 0;
		for(int i = 1; i <= tot; ++i){
			int u = g[i].u, v = g[i].v, w = g[i].w;
			u = getf(u), v = getf(v);
			if(u == v) continue;
			++cnt, cost += w;
			f[u] = v;
			nwmx = w;
			if(cnt == n + siz - 1) break;
		}
		mx = min(mx, nwmx);
		ans = min(ans, cost);
	}
	cout << ans << '\n';
	return 0;
}

