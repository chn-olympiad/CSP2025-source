#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+20,INF=0x3f3f3f3f;
struct node{
	int v,w;
	bool operator < (const node &B) const {
		return w>B.w;
	}
};
vector<node>edge[maxn];
pair<int,int>dis[maxn][maxn];
int vis[maxn];
void add(int u,int v,int w){
	edge[u].push_back({v,w});
	edge[v].push_back({u,w});
}
int c[maxn];
int n,m,k,flag=1;
priority_queue<node>q;
void dij(int s){
	for(int i=1;i<=n+k;i++) dis[s][i]={INF,i};
	dis[s][s].first=0;
	q.push({s,0});
	while(!q.empty()){
		node f=q.top();
		q.pop();
		int u=f.v;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<edge[u].size();i++){
			int v=edge[u][i].v;
			int w=edge[u][i].w;
			if(!vis[v]&&dis[s][v].first>dis[s][u].first+w){
				dis[s][v].first=dis[s][u].first+w;
				q.push({v,dis[s][v].first});
			}
		}
	}
}
int ans=0;
void dfs(int from,int x){
	ans+=dis[from][x].first;
	for(int i=1;i<=n+k;i++){
		if(!vis[dis[x][i].second]){
			vis[dis[x][i].second]=1;
			dfs(x,dis[x][i].second);
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
		add(u,v,w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[n+i];
		if(c[n+i]!=0) flag=0;
		int w;
		for(int j=1;j<=n;j++){
			cin>>w;
			if(w!=0) flag=0;
			add(n+i,j,w);
		}
	}
	if(k==0) flag=0;
	if(flag){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n+k;i++){
		dij(i);
		for(int j=1;j<=n+k;j++) vis[j]=0;
		sort(dis[i]+1,dis[i]+1+n+k);
	}
	vis[1]=1;
	dfs(1,1);
	cout<<ans;
	return 0;
}
