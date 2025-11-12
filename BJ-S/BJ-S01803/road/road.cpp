#include<bits/stdc++.h>
using namespace std;
struct node{
	int v;
	int cost;
}; int n,m,k,u,v,x,ans=1e9;
int a[10005][10005];
int b[10005];
bool vis[10005];
void dfs(int x,int cnt){
	bool flag=false;
	for(int i=1;i<=n;i++)
		if(vis[i]==0)
			flag=true;
	if(flag==false){
		ans=min(ans,cnt);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(a[x][i]!=1e9&&vis[i]==0){
			vis[x]=vis[i]=1;
			dfs(i,cnt+a[x][i]);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=1e9;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>x;
		a[u][v]=x;
	} 
	for(int i=1;i<=k;i++){
		cin>>x;
		for(int j=1;j<=n;j++)
			cin>>b[j];
		for(int k=1;k<=n;k++)
			for(int w=1;w<=n;w++)
				a[k][w]=min(b[k]+b[w],a[k][w]);
	} 
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		dfs(i,0);
	} cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
