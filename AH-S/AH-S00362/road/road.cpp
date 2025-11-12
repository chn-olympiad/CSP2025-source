#include <bits/stdc++.h>
using namespace std;
int mapp[1010][1010];
int a[1010][1010];
int n,m,k;
int u,v,w;
int ml=1;
int ans=INT_MAX;
bool vis[1010]={0};
void dfs(int u,int v,int r){
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[u]=true;
			dfs(i,v+mapp[u][i],r+1);
			vis[u]=false;
		}
	}
	if(r==ml){
		ans=min(ans,v);
	}
	return;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=2;i<n;i++){
		ml+=i;
	}
	for(int i=1;i<=n;i++){
		cin>>u>>v>>w;
		mapp[u][v]=w;		
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>a[i][j];	
		}
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
