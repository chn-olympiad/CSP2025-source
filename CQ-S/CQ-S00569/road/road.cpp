#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

const int maxn = 1e4 + 1, maxm = 1e6 + 1 ;
int n, m, k ;
struct node {
	int u, v, val ;
	bool operator < (const node &x) { return val < x.val ; }
} ;
ll ans ;
int fa[maxn], anc[maxn] ;
int w[maxn] ;
bool vis[11], fvis[11] ;
int xg[maxn] ;
int nxal[11], nw[11][maxn] ;
std::vector<node> G ;
std::vector<std::pair<int, int>> g[maxn] ;

int Get_fa(int u) {
	if(anc[u] == u) return u ;
	return anc[u] = Get_fa(anc[u]) ;
}

void Kruskal() {
	for(int i=1 ; i<=n ; i++) anc[i] = i ;
	std::sort(G.begin(), G.end()) ;
	int tot = 0 ;
	for(auto Id : G) {
		int u = Id.u, v = Id.v, val = Id.val ;
		int fu = Get_fa(u), fv = Get_fa(v) ;
		if(fu != fv) {
//			printf("%d %d %d\n", u, v, val) ;
			anc[fu] = fv ;
			++ tot ;
			ans += val ;
			g[u].push_back({v, val}) ;
			g[v].push_back({u, val}) ;
			if(tot == n - 1) break ;
		}
	}
}

void dfs(int u, int fh, int val) {
	fa[u] = fh ;
	w[u] = val ;
	for(auto next : g[u]) {
		int v = next.first ;
		if(v != fh) dfs(v, u, next.second) ;
	}
}

void func(int s, int nval) {
	ll cnt = 0 ;
	for(int i=1 ; i<=n ; i++) if(i != s && i != fa[s] && w[i] > nw[s][i]) cnt += w[i] - nw[s][i] ;
	if(w[s] > nw[s][fa[s]]) cnt += w[s] - nw[s][fa[s]] ;
//	printf("%d %lld %d\n", s, cnt, nval) ;
	if(cnt > nval) {
		for(int i=1 ; i<=n ; i++) {
			if(w[i] > nw[s][i] && i != s && i != fa[s]) w[i] = nw[s][i], xg[i] = s, fa[i] = s ;
		}
		if(w[s] > nw[s][fa[s]]) w[s] = nw[s][fa[s]], xg[fa[s]] = s ;
		ans -= (cnt - nval) ;
		vis[s] = true ;
	}
	return ;
}

signed main() {
	freopen("road.in", "r", stdin) ;
	freopen("road.out", "w", stdout) ;
	scanf("%d%d%d", &n, &m, &k) ;
	for(int i=1 ; i<=m ; i++) {
		int u, v, val ;
		scanf("%d%d%d", &u, &v, &val) ;
		G.push_back({u, v, val}) ;
	}
	Kruskal() ;
	dfs(n, n, 0) ;
//	for(int i=1 ; i<=n ; i++) printf("%d " , w[i]) ;
//	putchar('\n') ;
	for(int i=1 ; i<=k ; i++) {
		scanf("%d", &nxal[i]) ;
		for(int j=1 ; j<=n ; j++) scanf("%d", &nw[i][j]) ;
//		if(w[i] > nw[i][fa[i]]) puts("2") ;
//		printf("%d\n", i) ;
//		for(int j=1 ; j<=n ; j++) {
//			if(w[j] > nw[i][j]) puts("1") ;
//		}
		func(i, nxal[i] + nw[i][i]) ;
//		printf("%lld\n", ans) ;
	}
	for(int i=1 ; i<=n ; i++) fvis[xg[i]] = true ;
	for(int i=1 ; i<=k ; i++) {
		if(vis[i] && ! fvis[i]) ans -= (nxal[i] + nw[i][i]) ; 
	}
	printf("%lld\n", ans) ;
	return 0 ;
}
