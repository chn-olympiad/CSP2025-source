#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
const ll N = 3e6,inf = 1e17;
struct edge{
	ll u,v,w;
}e[N];int id[N];vector<edge>V,G;int n,m,k;ll c[N];
ll a[15][N];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int find(int x){
	if(id[x]==x) return x;
	else   return id[x] = find(id[x]);
}
void unite(int x,int y){
	int fx = find(x),fy = find(y);
	if(fx==fy) return;
	id[fy] = fx;
}
void kruscal(){
	sort(e+1,e+m+1,cmp);
	for(int i = 1;i<=m;i++){
		ll u = e[i].u,v = e[i].v,w = e[i].w;
		int fu = find(u),fv = find(v);
		if(fu==fv) continue;
		V.pb(e[i]);unite(u,v);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
    for(int i = 1;i<=m;i++){
    	ll u,v,w;scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i = 1;i<=n;i++) id[i] = i;
	kruscal();
	for(int i = 1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j = 1;j<=n;j++) scanf("%lld",&a[i][j]);
	}
	int S = (1<<k);ll mn = inf;
	for(int i = 0;i<S;i++){
		ll ans = 0;G.clear();
		if(k<=5&&m<=10000){
			for(int j = 1;j<=m;j++) G.pb(e[j]);
		}
		else{
		    for(int j = 0;j<V.size();j++) G.pb(V[j]);
	    }
		for(int j = 0;j<k;j++){
			if((i&(1<<j))>0){
				ans += c[j+1];
				for(int l = 1;l<=n;l++)	G.pb({l,j+1+n,a[j+1][l]});
			}
		}
		for(int j = 1;j<=n+k;j++) id[j] = j;
		sort(G.begin(),G.end(),cmp);
		for(int j = 0;j<G.size();j++){
			ll u = G[j].u,v = G[j].v,w = G[j].w;
			int fu = find(u),fv = find(v);
			if(fu==fv) continue;
			unite(u,v);ans += w;
		}
		mn = min(ans,mn);
	}
	cout<<mn;
	return 0;
}
