#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,dali25[1001][1001],c[11],a[11][1001],ans=100000000;
bool flag[1001][1001];
void dfs(int x,bool f,int cnt){
	if(f&&x>k) return ;
	if(x>n){
		ans=min(cnt,ans);
		return ;
	}
	if(f==1){
		for(int i=1;i<=n;i++){
		    if(flag[x][i]) continue;
		    flag[x][i]=1;
		    flag[i][x]=1;
		    dfs(x+1,1,cnt+a[x][i]+c[x]);
		    dfs(x+1,0,cnt+a[x][i]+c[x]);
		    flag[x][i]=0;
		    flag[i][x]=0;
    	}
    	return ;
	}
	for(int i=1;i<=n;i++){
		if(flag[x][i]) continue;
		flag[x][i]=1;
		flag[i][x]=1;
		dfs(x+1,1,cnt+dali25[x][i]);
		dfs(x+1,0,cnt+dali25[x][i]);
		flag[x][i]=0;
		flag[i][x]=0;
	}
	return ;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		dali25[u][v]=w;
		dali25[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	dfs(1,1,0);
	dfs(1,0,0);
	cout<<ans;
	return 0;
}