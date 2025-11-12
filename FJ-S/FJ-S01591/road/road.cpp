#include<bits/stdc++.h>
using namespace std;
const int N=1e4+1;
struct node{
	int v;
	long long w;
};
vector<node>adj[N];
int n,m,k;
long long dis[N],a[10][N],c[10],ans;
bool vis[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v;long long w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)	cin>>a[i][j];
	}
	//memset(dis,0x3f,sizeof(dis));dis[0]=0;
	for(int i=2;i<=n;i++)	dis[i]=LONG_LONG_MAX;
	u=1;
	while(u){
		vis[u]=1;dis[u]=0;
		for(node tar:adj[u]){
			if(!vis[tar.v])
			dis[tar.v]=min(dis[tar.v],tar.w);
		}w=LONG_LONG_MAX;v=0;
		for(int i=2;i<=n;i++){
			if(!vis[i]&&dis[i]<w){
				v=i;w=dis[i];
			}
		}
		ans+=dis[v];u=v;
	}
	cout<<ans;
	return 0;
}
