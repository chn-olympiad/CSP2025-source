#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
struct Edge{
	int u,v,w;
}edge[N];
int vis[1005][1005],a[10005],fa[10005];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,k,cnt=0,tot=0,ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++) vis[i][j]=INT_MAX;
	for(int i=1,x,y,z;i<=m;i++) cin>>x>>y>>z,vis[min(x,y)][max(x,y)]=z;
	for(int i=1,t;i<=k;i++){
		cin>>t;
		for(int j=1;j<=n;j++) cin>>a[j];
		for(int j=1;j<n;j++) for(int p=j+1;p<=n;p++) vis[j][p]=min(vis[j][p],a[j]+a[p]+t);
	}
	for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++) if(vis[i][j]!=INT_MAX) edge[++cnt]={i,j,vis[i][j]};
	sort(edge+1,edge+cnt+1,[&](Edge x,Edge y){return x.w<y.w;});
	for(int i=1;i<=cnt;i++){
		if(tot==n-1) break;
		int u=edge[i].u,v=edge[i].v,w=edge[i].w;
		if(find(fa[u])!=find(fa[v])) fa[v]=find(fa[u]),ans+=w,tot++; 
	}
	cout<<ans;
}
/*
6 8 1
1 2 2
2 3 4
3 4 5
4 5 7
5 6 8
1 6 1
2 6 3
1 4 6
0 10 10 10 3 3 10 
*/
