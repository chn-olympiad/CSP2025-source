#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans,cost[15];
bool vis[10005];
struct e{
	int v,w;
	friend bool operator<(e a,e b){
		return a.w<b.w;
	}
};
int g[10005][10005];
int c[15][10005];

void prim(){
	priority_queue<e> q;
	q.push({1,0});
	vis[1]=1;
	int cnt=1;
	while(cnt<n){
		int v=q.top().v;
		int w=q.top().w;
		if(!vis[v]){
			vis[v]=1;ans+=w;cnt++;
		}
		for(auto i:g[v]){
			if(!vis[i.v])q.push(i);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u][v]=g[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",cost+i);
		for(int j=0;j<m;j++){
			int w;
			scanf("%d",&w);
			c[i][j]=w;
		}
	}
	for(int p=1;p<=k;p++){
		for(int u=1;u<=n;u++)for(int v=u+1;v<=n;v++){
			int w=c[p][u]+c[p][v]+cost[p];
			g[u][v]=min(g[u][v],w);
			g[v][u]=g[u][v];
		}
	}
	prim();
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
}
