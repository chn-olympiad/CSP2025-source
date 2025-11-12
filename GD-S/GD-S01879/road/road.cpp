#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
ll n,m,k,vis[11000],dis[11000],ans,t[11000],flag[15],jg,c[15];
struct bian{
	ll v,w;
};
vector<bian>e[11000],el[15][11000];
void prim(ll s){
	memset(vis,0,sizeof(vis));
	memset(flag,0,sizeof(flag));
	for(int i=0;i<=n;i++)dis[i]=1e18;
	dis[1]=0;
//	vis[s]=1;
	for(ll i=1;i<=n;i++){
		ll u=0;
		for(ll j=1;j<=n;j++){
			if(dis[j]<dis[u]&&!vis[j])u=j;
		}
		ans+=dis[u];
		vis[u]=1;
		for(auto ed:e[u]){
			ll v=ed.v,w=ed.w;
			if(dis[v]>w){
				dis[v]=w;
//				cout<<u<<' '<<v<<' '<<w<<endl;
			}
		}
		if(s==0)continue;
		for(int j=1;j<=s;j++){
			for(auto ed:el[j][u]){
				ll v=ed.v,w=ed.w;
				if((!flag[j]&&dis[v]>w+c[j])){
					dis[v]=w;
					flag[j]=1;
					ans+=c[j];
				}
				else if(flag[j]&&dis[v]>w){
					dis[v]=w;
//					cout<<1;
				}
//				cout<<u<<' '<<v<<" "<<w<<' '<<j<<endl;
			}
		}
	}
	return;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
//		cout<<u<<"->"<<v<<"有条价值为"<<w<<"的边"<<endl;
//		cout<<v<<"->"<<u<<"有条价值为"<<w<<"的边"<<endl;
	}
	prim(0);
//	cout<<ans<<endl;
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++){
			cin>>t[j];
		}
		ll z=ans;
		ans=0;
		for(ll j=1;j<=n;j++){
			for(ll l=j+1;l<=n;l++){
				el[i][j].push_back({l,t[j]+t[l]});
				el[i][l].push_back({j,t[j]+t[l]});
//				cout<<j<<"->"<<k<<"有条价值为"<<t[j]+t[k]+c<<"的边"<<endl;
//				cout<<k<<"->"<<j<<"有条价值为"<<t[j]+t[k]+c<<"的边"<<endl;
			}
		}
		prim(i);
//		cout<<ans<<endl;
		if(ans>z)ans=z;
	}
//	prim(k);
	cout<<ans;
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 1 1 1
100 1 3 2 4
*/
