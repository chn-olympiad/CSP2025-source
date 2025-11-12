#include<bits/stdc++.h>
using namespace std;
int n,m,k;

//struct edge{
//	int v,w;
//};
//bool vis1[11000];
//vector<edge>a[11000];
//bool pd(int start,int end){
//	if(vis[start])return 0;
//	vis[start]=1;
//	if(start==end){
//		return 1;
//	}
//	for(int i:a[start]){
//		return dfs(a[i].v);
//	}
//}
//void dfs(int x,int ans){
//	for(int i:a[x]){
//		
//	}
//}
int dis[1100][1100];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e9;
		}
		dis[i][i]=0;
	}
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		//a[u].push_back({v,w});
		//a[v].push_back({u,w});
		dis[u][v]=dis[v][u]=w;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(dis[i][j]!=1e9)ans+=dis[i][j];//cout<<dis[i][j]<<" ";
		}
		//cout<<"\n";
	}	
	cout<<ans;
	return 0;
}

