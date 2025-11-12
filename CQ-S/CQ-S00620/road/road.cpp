#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const int N = 1e4 + 10, M = 1e6 + 10, K = 11;
int n, m, k, tot;
struct Edge{
	int u, v;LL w;
	bool operator<(const Edge &a){
		return w < a.w;
	}
}edges[M];

int fa[N], siz[N];
int find(int x){return x == fa[x] ? x : fa[x] = find(fa[x]);}
void merge(int x, int y){
	x = find(x); y = find(y);
	if(x == y) return;
	if(siz[x] > siz[y]) swap(x, y);
	if(siz[x] == siz[y]) siz[y]++;
	fa[x] = y;
}

LL ans, maxe, c[K][N], cst[K];

void kruskal(){
	sort(edges + 1, edges + tot + 1);
	for(int i = 1; i <= n; i++) fa[i] = i, siz[i] = 0;
	ans = 0;
	int cnt = 0;
	for(int i = 1; i <= tot; i++){
		int u = edges[i].u , v = edges[i].v ;LL w = edges[i].w;
		if(find(u) == find(v)) continue;
		merge(u, v);
		maxe = max(w, maxe);
		cnt++;
		ans += w;
		if(cnt == n - 1) break;
	}
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int u, v; LL w;
		cin >> u >> v >> w;
		edges[i] = {u, v, w}; 
	}
	for(int i = 1; i <= k; i++){
		cin >> cst[i];
		for(int j = 1; j <= n; j++){
			cin >> c[i][j];
		}
	}
	tot = m;	
	kruskal();
	for(int i = 1; i <= k; i++){
		if(cst[i] >= maxe) continue;
		for(int u = 1; u <= n; u++){
			if(c[i][u] + cst[i] >= maxe) continue;
			for(int v = 1; v <= n; v++){
				if(u == v) continue;
				LL w = c[i][u] + c[i][v];
				if(w > maxe) continue;
				edges[++tot] = {u, v, w};
			}
		}
	}
	kruskal();
	cout << ans;
	return 0;
}
