#include<bits/stdc++.h>
using namespace std;
int sum=0,vis[100005];
int n,m,k;
struct s{
	int u,v,w;
}road[100006];
void dfs(int dep,int a){
	sum=max(sum,a);
	for(int i=0;i<m;i++){
		if(road[i].u==dep && vis[road[i].v]==0){
			vis[road[i].v]=1;
			dfs(i,a+road[i].w);
			vis[road[i].v]=0;
		}else if(road[i].v==dep && vis[road[i].u]==0){
			vis[road[i].u]=1;
			dfs(i,a+road[i].w);
			vis[road[i].u]=0;
		}
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(vis,0,sizeof(vis));
	int vill[10004][11];
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>road[i].u>>road[i].v>>road[i].w;
	}
	for(int i=0;i<k;i++){
		cin>>vill[0][i];
		for(int j=1;j<=n;j++){
			cin>>vill[j][i];
		}
	}
	for(int i=0;i<n;i++){
		memset(vis,0,sizeof(vis));
		dfs(i,0);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
