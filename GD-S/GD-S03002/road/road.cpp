#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n,m,k;
int G[N][N];
int c[12],a[12][N];//,vis[12];
int slove(){
	cin>>n>>m>>k;
	memset(G,0x3f,sizeof G);
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>w>>v>>w;
		G[v][u]=G[u][v]=min(w,G[v][u]);
	}
	for(int i=1;i<=n;i++)G[i][i]=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
		for(int u=1;u<=n;u++){
			for(int v=u+1;v<=n;v++){
				if(a[i][u]+a[i][v]<G[u][v]){
					G[v][u]=G[u][v]=a[i][u]+a[i][v];
				}
			}
		}
	}
	long long ans=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0,1});
	while(!pq.empty()){
		int u=pq.top().second,w=pq.top().first;
		pq.pop();
		for(int v=1;v<=n;v++){
			if(G[u][v]==0x3f)continue;
			if(w+G[u][v]<G[1][v]){
				G[v][1]=G[1][v]=w+G[u][v];
				pq.push({G[v][1],v});
			}
		}
	}
	for(int i=2;i<=n;i++){
		ans+=G[i][1];
	}cout<<ans;
	return 0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int t=1;//cin>>t;
	while(t--)
		slove();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
