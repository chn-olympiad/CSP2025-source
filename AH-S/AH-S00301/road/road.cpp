#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct stu{
	ll v,w;
};
ll n,n1,m,k,c[15],F[15][10005],dis[10015];
vector<stu> G[10015];
bool vis[10015];
ll mst_Prim(){
	memset(dis,0x3f,sizeof dis);
	ll mst=0;
	dis[1]=0;
	while(1){
		ll u=-1;
		for(int i=1;i<=n;i++){
			if(!vis[i]&&(u==-1||dis[i]<dis[u])){
				u=i;
			}
		}
		if(u==-1){
			break;
		}
		vis[u]=1;
		mst+=dis[u];
		for(int i=0;i<G[u].size();i++){
			if(dis[G[u][i].v]>G[u][i].w){
				dis[G[u][i].v]=G[u][i].w;
			}
		}
	}
	return mst;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	n1=n;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]==0){
			n++;
		}
		for(int j=1;j<=n1;j++){
			cin>>F[i][j];
			if(c[i]==0){
				G[j].push_back({n,F[i][j]});
				G[n].push_back({j,F[i][j]});
			}
		}
	}
	cout<<mst_Prim();
	return 0;
}
