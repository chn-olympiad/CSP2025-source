#include <bits/stdc++.h> 
typedef long long ll; 
using namespace std; 

const int M = 1e6 + 5, N = 1e4 + 5, MM = 2e6 + 5, K = 15; 

int n, m, k, fa[N], p[N];       

ll a[K][N], c[K], ans, quan[N]; 

bool vis[N]; 

int hd[N], cnt_e; 

struct ED {
	int nxt, to;
	ll val; 
} edge[MM]; 

struct PH {
	int fr, to;
	ll we; 
} ed[M]; 

void adde(int u, int v, ll w) {
	edge[++cnt_e].nxt = hd[u], edge[cnt_e].to = v, edge[cnt_e].val = w; 
	hd[u] = cnt_e; return;           
} 

bool cmp(PH x, PH y) {
	return x.we < y.we; 
} 

int find(int x) {
	if(fa[x] == x) return x; 
	return fa[x] = find(fa[x]); 
}

void Kruskal() { 
	ll Ans = 0;
	int cnte = 0; 
	sort(ed + 1, ed + m + 1, cmp); 
	for(int i = 1; i <= n; i++) fa[i] = i; 
	for(int i = 1; i <= m; i++) { 
		int x = ed[i].fr, y = ed[i].to; ll z = ed[i].we; 
		int fx = find(x), fy = find(y); 
		if(fx != fy) {
			fa[fx] = fy;  
			Ans += z; 
			cnte++; 
		} 
		if(cnte == n - 1) break; 
	} 
	printf("%lld\n", Ans);    
	return;     
}

void ktree() { 
	int cnte = 0;
	sort(ed + 1, ed + m + 1, cmp); 
	for(int i = 1; i <= n; i++) fa[i] = i; 
	for(int i = 1; i <= m; i++) { 
		int x = ed[i].fr, y = ed[i].to; ll z = ed[i].we; 
		int fx = find(x), fy = find(y); 
		if(fx != fy) {
			fa[fx] = fy;  
			ans += z; 
			cnte++; 
			adde(x, y, z), adde(y, x, z); 
		} 
		if(cnte == n - 1) break; 
	}     
	return;     
}

void dfs(int u, int fath) {
	p[u] = fath; 
	for(int i = hd[u]; i; i = edge[i].nxt) { 
		int v = edge[i].to; 
		if(v == fath) continue; 
		quan[v] = edge[i].val; 
		dfs(v, u); 
	} 
	return; 
}

int main() {
	freopen("road.in", "r", stdin); 
	freopen("road.out", "w", stdout);   
	scanf("%d %d %d", &n, &m, &k); 
	for(int i = 1; i <= m; i++) {
		int u, v; ll w; 
		scanf("%d %d %lld", &u, &v, &w); 
//		adde(u, v, w), adde(v, u, w); 
		ed[i].fr = u, ed[i].to = v, ed[i].we = w; 
	} 
	bool flagA = 1; 
	for(int i = 1; i <= k; i++) {
		scanf("%lld", &c[i]); 
		for(int j = 1; j <= n; j++) {
			scanf("%lld", &a[i][j]); 
		}
	} 
	if(k == 0) {
		Kruskal(); 
		return 0; 
	}
	ktree(); 
	dfs(1, 0); 
//	for(int i = 1; i <= n; i++) cout << quan[i] << endl;  
//	for(int i = 1; i < lim; i++) {
		for(int j = 1; j <= k; j++) {
//			if(i & (1 << j)) { 
				for(int i = 1; i <= n; i++) vis[i] = 0; 
				ll tpans = ans;  //vis[i] = 0; 
				ll tmp = 0, minn = 1e10;   
				for(int I = 1; I <= n; I++) {
					if(quan[I] >= a[j][I]) tmp += quan[I] - a[j][I], vis[I] = 1;        
				}   
				for(int i = 1; i <= n; i++) if(!vis[i]) minn = min(a[j][i], minn); 
				if(tmp > c[j]) { 
					tpans = tpans - tmp - c[j] + minn; 
					for(int i = 1; i <= n; i++) if(quan[i] >= a[j][i]) quan[i] = a[j][i]; 
					ans = min(ans, tpans);  
				}
//			}               
		}
//	}
	printf("%lld\n", ans); 
	return 0;     
}
