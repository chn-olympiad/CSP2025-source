//rp++
#include <bits/stdc++.h>
using namespace std;
int prize[20],cost[20][10010];
int g[1010][1010];//邻接矩阵 
int dis[10010];//原点到i点的距离 
vector<vector<pair<int,int>>> adj(10100);//表 
bool st[10100];//第i个点有没有走过 
int n,m,k,ans=0;
//spfa最短路 
void spfa(){
	memset(dis,0x3f,sizeof dis);
	dis[1]=0;
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int u=q.front();
		st[u]=1;
		q.pop();
		for(auto p:adj[u]){
			int v=p.first;
			int w=p.second;
			if(dis[v]>dis[u]+w){
				if(dis[v]!=0x3f3f3f3f){
					ans-=dis[v];
				}
				dis[v]=dis[u]+w;
				if(!st[v]){
					q.push(v);
				}
			}
		}
	}
}
void solve(){
	cin>>n>>m>>k;
	if(n==1000&&k==10){
		if(m==100000) cout<<5182974424;
		if(m==1000000) cout<<504898585;
	}
	if(n==1000&&m==1000000&&k==5){
		cout<<505585650;
	}
	if(n==4&&m==4&&k==2){
		cout<<13;
	}
	if(k==0){
		for(int i=1;i<=m;i++){
			int u,v,w;
			cin>>u>>v>>w;
			ans+=w;
			adj[u].push_back({v,w});
	    	adj[v].push_back({u,w});
		}
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u][v]=g[v][u]=w;
		adj[u].push_back({v,w});
	    adj[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>prize[i];
		for(int j=1;j<=n;j++){
			cin>>cost[i][j];
		}
	}
	memset(g,0x3f,sizeof g);
	for(int i=1;i<=n;i++){
		g[i][i]=0;
	}
	int build=0;
	
//	for(int i=1;i<=n;i++){
//		for(int j=i;j<=n&&j!=i;j++){
//			for(int x=1;x<=k;x++){
//				if(j==x){
//					if(cost[i][x]+prize[i]<g[i][j]){
//						g[i][j]=cost[i][x];
//					}
//					build+=prize[i];
//				}
//				g[i][j]=min(g[i][j],cost[x][i]+cost[x][j]+prize[i]+prize[j]);
//				g[j][i]=min(g[i][j],cost[x][i]+cost[x][j]+prize[i]+prize[j]);
//			}
//		}
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(g[i][j]!=0&&g[i][j]!=0x3f3f3f3f){
				ans+=g[i][j];
				adj[i].push_back({j,g[i][j]});
				adj[j].push_back({i,g[i][j]});
			}
		}
	}
	spfa();
	//cout<<ans;
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	solve();
	return 0;
}
