#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
struct nd{
	int v,w;
};
int n,m,k,ans=INT_MAX,a[N][N],c[N];
vector<nd> g[N];
bool vis[N][N],vv[N];
bool dfs2(int x,int s){
	if(s==n-1){
		bool b=1;
		for(int i=1;i<=n;i++){
			if(!vv[i]) b=0;
		}
		return b;
	}
	for(int i=1;i<=n;i++){
		if(vis[x][i]){
			vv[i]=1;
			if(dfs2(i,s+1)) return 1;
			vv[i]=0;
		}
	}
	return 0;
}
void dfs1(int s,int sum){
	if(sum>=ans) return;
	if(s==n-1){
		vv[1]=1;
		if(dfs2(1,0)) ans=min(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<g[i].size();j++){
			if(!vis[i][g[i][j].v]){
				vis[i][g[i][j].v]=1;
				vis[g[i][j].v][i]=1;
				dfs1(s+1,sum+g[i][j].w);
				vis[i][g[i][j].v]=0;
				vis[g[i][j].v][i]=0;
			}
		}
	}
}
int main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	dfs1(0,0);
	cout<<ans;
	return 0;
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
