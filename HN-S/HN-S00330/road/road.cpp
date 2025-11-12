#include<bits/stdc++.h>
#define N 10086
#define MMAX 100000000000000
#define ll long long
using namespace std;
int n,m,k,c[18],g[N][N];
ll ans=MMAX;
bool used[N];
void dfs(ll sum,int now,int cnt);
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++){
		for(int j=1;j<=n+k;j++) g[i][j]=INT_MAX;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u][v]=g[v][u]=min(g[u][v],w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>g[n+i][j];
			g[n+i][j]=g[j][n+i];
		}
	}
	for(int i=1;i<=n;i++) dfs(0,i,1);
	cout<<ans<<endl;
	return 0;
}
void dfs(ll sum,int now,int cnt){
	if(sum>=ans) return;
	if(cnt==n) ans=min(ans,sum);
	for(int i=1;i<=n;i++){
		if(!used[i] && g[now][i]!=INT_MAX){
			used[i]=1;
			dfs(sum+g[now][i],i,cnt+1);
			used[i]=0;
		}
	}
	if(now<=n){
		for(int i=1;i<=k;i++){
			if(!used[i+n]){
				used[i+n]=1;
				dfs(sum+c[i]+g[now][n+i],n+i,cnt);
				used[i+n]=0;
			}
		}
	}
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
