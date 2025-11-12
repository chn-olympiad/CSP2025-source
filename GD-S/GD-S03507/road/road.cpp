#include<bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;

int n, m, k;
struct DSU{
	int fa[10015], siz[10015];
	void init(int n){
		for(int i = 1; i <= n; i++){
			fa[i] = i, siz[i] = 1;
		}
	}	
	int find(int x){
		if(fa[x] == x) return x;
		return fa[x] = find(fa[x]);
	}
	void merge(int x, int y){
		int fx = find(x), fy = find(y);
		if(fx == fy) return;
		if(siz[fx] < siz[fy]){
			swap(fx, fy);
		} 
		fa[fy] = fx;
		siz[fx] += siz[fy];
	}
	bool same(int x, int y){
		return find(x) == find(y);
	}
}dsu;
struct node{
	int u, v, w;
}edges[1100005];
int c[15], a[15][10005];
bool b[15];

bool cmp(node a, node b){
	return a.w < b.w;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; i++){
		scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
	}
	int maxn = 0;
	for(int i = 1; i <= k; i++){
		scanf("%d", &c[i]);
		maxn = max(maxn, c[i]);
		for(int j = 1; j <= n; j++){
			scanf("%d", &a[i][j]);
			edges[++m] = {n + i, j, a[i][j]};
		}
	}
	sort(edges + 1, edges + m + 1, cmp);
	ll ans = 1ll << 60;
	int s = 0;
	if(maxn == 0) s = (1 << k) - 1;
	for(int i = s; i < (1 << k); i++){
		ll sum = 0;
		memset(b, false, sizeof(b));
		for(int j = 0; j < k; j++){
			if((i >> j) & 1){
				sum += c[j + 1];
				b[j + 1] = true;
			}
		}
		dsu.init(n + k);
		for(int j = 1; j <= m; j++){
			int u = edges[j].u, v = edges[j].v;
			if((u <= n || b[u - n]) && (v <= n || b[v - n])){
				if(!dsu.same(u, v)){
					sum += edges[j].w;
					dsu.merge(u, v);
				}
			}
		}
		ans = min(ans, sum);
	}
	printf("%lld\n", ans);
	return 0;
}
