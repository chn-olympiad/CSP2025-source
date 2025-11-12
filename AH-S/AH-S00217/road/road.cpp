#include <bits/stdc++.h>
using namespace std;
vector<long long>g[10005];
bool f[10005];
void addedge(int u,int v,int w){
	g[u][v]=w;
	g[v][u]=w;
}
long long n,m,k;
long long dfs(int x,int i){
	if (i==n)
		return 0;
	long long ans=1e10;
	f[x]=1;
	for (int j=1;j<=n;j++){
		if (f[j])
			continue;
		ans=min(ans,g[x][j]+dfs(j,i+1));
	}
	f[x]=0;
	return ans;
}
int main(){
	freopen ("road.in","r",stdin);
	freopen ("road.out","w",stdout);
	scanf ("%lld%lld%lld",&n,&m,&k);
	long long u,v,w;
	for (int i=1;i<=m;i++){
		scanf ("%lld%lld%lld",&u,&v,&w);
		addedge(u,v,w);
	}
	long long tmp,qx;
	for (int i=1;i<=m;i++){
		scanf ("%lld",&tmp);
		for (int j=1;j<=n;j++){
			scanf ("%lld",&qx);
			if (qx<=g[i][j]||g[i][j]==0)
				g[i][j]=qx;
		}
	}
	long long ans=1e10;
	for (int i=1;i<=n;i++)
		ans=min(ans,dfs(i,0));
	return 0;
}
