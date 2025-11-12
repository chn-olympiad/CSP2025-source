#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
int n,m,k,vis[10100],dis[10100],c[15],mp[15][10100],f[15];
struct node{
	int v,w;
}; 
vector<node>e[10100];
void prim(){
	for(int i=0;i<=n;i++) dis[i]=1e9;
	dis[1]=0;
	for(int i=1;i<=n;i++){
		int u=0;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&dis[j]<dis[u]){
				u=j;
			}
		}
		vis[u]=1;
//		cout<<u<<":";
		for(int j=0;j<e[u].size();j++){
			int v=e[u][j].v,w=e[u][j].w;
			if(!vis[v]&&dis[v]>w){
				dis[v]=w;
//				cout<<v<<" "<<dis[v]<<endl;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans+=dis[i];
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++) cin>>c[i];
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>mp[i][j];
		}
	}
	if(k==0) prim();
	return 0;
}
