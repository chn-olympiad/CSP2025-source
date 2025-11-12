#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
int n,m,k;
const int N=1e6+5;
vector<pair<int,int>> g[N];
int c[15],a[15][N],dis[N];
bool vis[N];
void dij(){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	q.push({0,1});
	vis[1]=1;
	dis[1]=0;
	memset(dis,0x3f,sizeof(dis));
	while(q.size()){
		int u=q.top().second;
		q.pop();
		vis[u]=0;
		for(auto x:g[u]){
			int v=x.first,w=x.second;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				if(!vis[v]){
					vis[v]=1;
					q.push({dis[v],v});
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	dij();
	cout<<dis[n];
	return 0;
}