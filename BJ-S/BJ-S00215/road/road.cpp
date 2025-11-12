#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 1e4+15, MAXM = 1e6+5;
const ll INF = 1e18;

int n, m, k, cnt; ll w, rem = INF;
int fa[MAXN], siz[MAXN], chs[MAXM];
ll c[15], ans[1025];
vector <int> vec;

int gf(int node){
	if (fa[node] == node) return node;
	fa[node] = gf(fa[node]);
	return fa[node];
}

void merge(int u, int v){
	if (siz[u] < siz[v]) swap(u, v);
	siz[u] += siz[v]; fa[v] = u;
}

struct E{
	int u, v; ll w;	
} e[MAXM], op[15][MAXN], tmp[1025][MAXN];

bool cmp(E a, E b){
	return a.w < b.w;
}

int main(){
	freopen("road.in", "r", stdin); freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i=1; i<=m; i++) scanf("%d%d%lld", &e[i].u, &e[i].v, &e[i].w);
	for (int i=1; i<=k; i++){
		scanf("%lld", &c[i]);
		for (int j=1; j<=n; j++) scanf("%lld", &w), op[i][j] = {n+i, j, w};
		sort(op[i]+1, op[i]+n+1, cmp);
	}
	sort(e+1, e+m+1, cmp);
	for (int i=1; i<=n+k; i++) fa[i] = i, siz[i] = 1;
	for (int i=1; i<=m; i++){
		int u = e[i].u, v = e[i].v; ll w = e[i].w;
		int fa1 = gf(u), fa2 = gf(v);
		if (fa1 == fa2) continue; merge(fa1, fa2); chs[i] = 1; ans[0] += w;
	} 
	for (int i=1; i<=m; i++){
		if (chs[i] == 1) cnt++, tmp[0][cnt] = e[i];
	}
	/*printf("debug: %d\n", 0);
	for (int j=1; j<=n-1; j++){
		printf("%d %d %lld\n", tmp[0][j].u, tmp[0][j].v, tmp[0][j].w);
	} printf("res = %lld\n", ans[0]);*/
	for (int i=1; i<(1<<k); i++){
		int pos = 0, popc = 0; ll pre = 0;
		for (int j=1; j<=k; j++){ if ((i>>(j-1))&1){ pos = j; popc++; pre += c[j]; } } 
		int lst = (i^(1<<(pos-1))), l = 1, r = 1, cnt = 0;
		for (int j=1; j<=n+k; j++) fa[j] = j, siz[j] = 1; 
		while (cnt < n+popc-1){
			if (r > n){
				int u = tmp[lst][l].u, v = tmp[lst][l].v; ll w1 = tmp[lst][l].w; l++;
				int fa1 = gf(u), fa2 = gf(v);
				if (fa1 == fa2) continue;
				merge(fa1, fa2); cnt++; tmp[i][cnt] = tmp[lst][l-1]; ans[i] += w1;
				continue;	
			}
			if (l > n+popc-2){
				int u = op[pos][r].u, v = op[pos][r].v; ll w2 = op[pos][r].w; r++;
				int fa1 = gf(u), fa2 = gf(v);
				if (fa1 == fa2) continue;
				merge(fa1, fa2); cnt++; tmp[i][cnt] = op[pos][r-1]; ans[i] += w2;
				continue;	
			}
			ll w1 = tmp[lst][l].w, w2 = op[pos][r].w;
			if (w1 < w2){ 
				int u = tmp[lst][l].u, v = tmp[lst][l].v; l++;
				int fa1 = gf(u), fa2 = gf(v);
				if (fa1 == fa2) continue;
				merge(fa1, fa2); cnt++; tmp[i][cnt] = tmp[lst][l-1]; ans[i] += w1;
			}	
			else{ 
				int u = op[pos][r].u, v = op[pos][r].v; r++;
				int fa1 = gf(u), fa2 = gf(v);
				if (fa1 == fa2) continue;
				merge(fa1, fa2); cnt++; tmp[i][cnt] = op[pos][r-1]; ans[i] += w2;
			}
		} 
		ans[i] += pre;
		/*printf("debug: %d\n", i);
		for (int j=1; j<=n+popc-1; j++){
			printf("%d %d %lld\n", tmp[i][j].u, tmp[i][j].v, tmp[i][j].w);
		} printf("res = %lld\n", ans[i]);*/
	} 
	for (int i=0; i<(1<<k); i++) rem = min(rem, ans[i]);
	printf("%lld\n", rem);
	//cerr << clock()*1.0/CLOCKS_PER_SEC << "\n";
	return 0;
}