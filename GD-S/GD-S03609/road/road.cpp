#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define ll long long
#define p(x,y) make_pair(x,y)
using namespace std;
int n,m,k,x,y,w,c[15],a[15][10005],f[10005];
ll ans=0x3f3f3f3f3f3f3f;
bool vis[10005],costk[15];
priority_queue<pair<int,int> >q;
vector<pair<int,int> >g[10005];
void dfs(int t,int u,int c){
	if(t>=n){
		ans=min(ans,(ll)(c));
		return;
	}
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i].first;
		int w=g[u][i].second;
		if(vis[v])continue;
		vis[v]=1;
		dfs(t+1,v,c+w);
		vis[v]=0;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&w);
		g[x].push_back(p(y,w));
		g[y].push_back(p(x,w));
	}
	for(int i=1;i<=k;i++){
		scanf("%d",c+i);
		for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(1,i,0);
		vis[i]=0;
	}
	printf("%lld",ans);
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
