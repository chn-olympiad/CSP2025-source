#include<bits/stdc++.h> 
using namespace std;
const int N=1e3+20,M=1e6+5;
int n,m,k;
int u,v,w;
int road[N][N];
int vil[50];
int root[N],vi[N];
void gi() {
	for(int i=1;i<=n;i++)
		root[i]=-1;
}
void dij(int root,int sum){
	vis[root]=1;
	if(root[i]!=-1)
		root[i]=min(root[i],sum);
	else root[i]=sum;
	
	for(int i=1;i<=n;i++){
		if(road[root][i]&&!vi[i]){
			dij(i,sum+road[root][i]+vil[i]);
		}
	}
	
}
int main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>u>>v>>w;
		road[u][v]=w;
		road[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>vil[i];
		for(int j=1;j<=n;j++){
			cin>>w;
			road[i+n][j]=w;
			road[j][i+1]=w;
		}
	}
	
	
	return 0;
}
