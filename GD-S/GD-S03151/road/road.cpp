#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int v[10010]={};
vector<vector<int>> g(10010,(vector<int>(10010,0)));
int ans=1e9;

bool cmp(){
	for(int i=0;i<n;i++){
		if(i==0) return 0;
	}
	return 1;
}

void dfs(int nw,int nd){
	if(nw=-1){
		for(int i=0;i<n;i++){
			v[i]=1;
			dfs(i,0);
			v[i]=0;
		}
	}
	if(cmp()){
		ans=min(ans,nw);
		return;
	}
	for(int i=0;i<n;i++){
		if(g[nw][i]!=0&&v[i]==0){
			v[i]=1;
			dfs(i,nd+g[nw][i]);
			v[i]=0;
		}
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	
	cin>>n>>m>>k;
	
	int xiang[20][10020]={};
	int u,v,w;
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		g[u][v]=w;
		g[v][u]=w;
	}
	for(int i=0;i<k;i++){
		cin>>xiang[i][0];
		for(int j=1;j<=n;j++)
		cin>>xiang[i][j];
	}
	dfs(-1,0);	
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
