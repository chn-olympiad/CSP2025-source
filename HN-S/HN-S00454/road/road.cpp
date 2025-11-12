#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,fa[1005],c[15],a[15][1005],cost;
bool chg[15];
struct rd{
	int u,v,w;
}g[1000005];
int find(int x){
	if(fa[x] == x)return x;
	return fa[x] = find(fa[x]);
}
bool cmp(rd a,rd b){return a.w < b.w;}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i = 1; i <= m; i ++){
		cin>>g[i].u>>g[i].v>>g[i].w;
		fa[i] = i;
	}
	fa[n] = n;
	for(int i = 1; i <= k; i ++){
		cin>>c[i];
		if(c[i] == 0)chg[i] = 1;
		for(int j = 1; j <= n; j ++){
			cin>>a[i][j];
			if(c[i] == 0 && a[i][j] == 0)fa[find(i)] = find(j);
		}
	}
	sort(g + 1,g + m + 1,cmp);
	for(int i = 1; i <= m; i ++){
		if(find(g[i].u) != find(g[i].v)){
			int t = 1e18,id = 0;
			for(int i = 1; i <= k; i ++){
				if(chg[k]){
					if(t < a[k][g[i].u] + a[k][g[i].v]){
						t = a[k][g[i].u] + a[k][g[i].v];
						id = i;
					}
				}else{
					if(t < c[k] + a[k][g[i].u] + a[k][g[i].v]){
						t = c[k] + a[k][g[i].u] + a[k][g[i].v];
						id = i;
					}
				}
			}
			if(t > g[i].w)cost += g[i].w;
			fa[find(g[i].w)] = find(g[i].v);
		}
	}
	cout<<cost;
	return 0;
}
