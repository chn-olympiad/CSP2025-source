#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,m,k;
vector<pii> G[10005];
struct node{
	int u,v,w;
	bool operator < (const node& x) const {
		return x.w>w; 
	}
};
node e[1000005],e2[1000005];
namespace sub1{
	int fa[10005];
	int fnd(int u){
		if(fa[u]!=u)
			fa[u]=fnd(fa[u]);
		return fa[u];
	}
	void sol(){
		for(int i=1;i<=n;i++)
			fa[i]=i;
		sort(e+1,e+m+1);
		int ans=0;
		for(int i=1;i<=m;i++){
			int fu=fnd(e[i].u),fv=fnd(e[i].v); 
			if(fu==fv)
				continue;
			ans+=e[i].w;
			fa[fu]=fv;
		}
		cout<<ans<<endl;
	}
}
namespace sub2{
	int fa[10005];
	int a[15][10005],tmp[15],tt[15];
	int vis[10005][10005];
	int fnd(int u){
		if(fa[u]!=u)
			fa[u]=fnd(fa[u]);
		return fa[u];
	}
	void sol(){
		for(int i=1;i<=n;i++)
			fa[i]=i;
		for(int i=1;i<=k;i++){
			cin>>tmp[i];
			for(int j=1;j<=n;j++){
				cin>>a[i][j];
				if(a[i][j]==0)
					tt[i]=j;
			}
		}
		int ans=0;
		for(int i=1;i<=k;i++){
			for(int u=1;u<=n;u++){
				for(auto v:G[u]){
					if(fnd(u)!=fnd(v.fi)&&(v.se==0||v.se>a[i][v.fi]+a[i][u])){
						ans+=a[i][v.fi]+a[i][u];
						v.se=a[i][v.fi]+a[i][u];
						fa[fnd(u)]=fnd(v.fi);
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w; 
		e[i]={u,v,w};
		G[u].pb({v,w});
		G[v].pb({u,w});
	}
	if(k==0){
		sub1::sol();
		return 0;
	}
	else{
		sub2::sol();
	}
	return 0;
}

