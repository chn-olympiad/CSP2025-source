#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N =1E4+10,M = 1e6+10;


ll ans,n,m,k,t,c[N],a[15][N],fa[N];
struct EDGE{
	ll u,v,w;
}e[M];

struct NODE{
	ll v,w;
};
vector<NODE> g[N];

ll find(ll x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

void unionn(ll x,ll y){
	ll fa_x = find(x);
	ll fa_y = find(y);
	fa[fa_x] = fa_y;
}

bool cmp(EDGE a,EDGE b){
	return a.w<b.w;
}

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	if(k==0){
		for(int i=1;i<=m;i++){
			ll u,v,w;
			cin>>u>>v>>w;  
			e[i] = {u,v,w};
		}
		
		sort(e+1,e+1+m,cmp);
		for(int i=1;i<=m;i++){
			ll u = e[i].u,v = e[i].v,w = e[i].w;
			if(find(u)!=find(v)){
				g[u].push_back({v,w});
				g[v].push_back({u,w});
				unionn(u,v);
				ans+=w;
			}
		}
		cout<<ans;
	}
	if(n<=3000){
		for(int i=1;i<=m;i++){
			ll u,v,w;
			cin>>u>>v>>w;  
			e[i] = {u,v,w};
		}
		for(int i=1;i<=k;i++){
			cin>>c[i];
			for(int j=1;j<=n;j++) cin>>a[i][j];
		}
		ll cnt=n;
		for(int i=1;i<=k;i++){
			for(int u=1;u<=n;u++)
			for(int v=u+1;v<=n;v++){
				e[++cnt] = {u,v,a[i][u]+c[i]+a[i][v]};
			}
		}
		sort(e+1,e+1+cnt,cmp);
		for(int i=1;i<=cnt;i++){
			ll u = e[i].u,v = e[i].v,w = e[i].w;
			if(find(u)!=find(v)){
				g[u].push_back({v,w});
				g[v].push_back({u,w});
				unionn(u,v);
				ans+=w;
			}
		}
		cout<<ans;
	}
	else{
	for(int i=1;i<=m;i++){
			ll u,v,w;
			cin>>u>>v>>w;  
			e[i] = {u,v,w};
		}
		
		sort(e+1,e+1+m,cmp);
		for(int i=1;i<=m;i++){
			ll u = e[i].u,v = e[i].v,w = e[i].w;
			if(find(u)!=find(v)){
				g[u].push_back({v,w});
				g[v].push_back({u,w});
				unionn(u,v);
				ans+=w;
			}
		}
		cout<<ans;	
	}
	
	

	
	
	

	
	
	return 0;
}
