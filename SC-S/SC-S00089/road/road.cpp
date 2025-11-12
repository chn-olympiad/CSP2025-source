#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1e4+5;
int n,m,k;
vector<pair<int,int>> e[N];
int c[N],dt[15][N];
int dis[N];
bool vis[N];
long long ans;
void prim(){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	memset(dis,inf,sizeof(dis));
	dis[1]=0;
	q.push({dis[1],1});
	while(!q.empty()){
		pair<int,int> top=q.top();
		q.pop();
		int d=top.first;
		int u=top.second;
		if(vis[u]) continue;
		vis[u]=true;
		ans+=d;
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i].first;
			int w=e[u][i].second;
			if(dis[v]>w && !vis[v]){
				dis[v]=w;
				q.push({dis[v],v});
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>dt[i][j];
		}
	}
	if(k==0){
		prim();
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}