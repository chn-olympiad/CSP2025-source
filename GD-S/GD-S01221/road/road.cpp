//code by ZXZMC
//不会prim,只会kruskal,完辣 15pts
//T2 AK ME
#include<bits/stdc++.h>
#define csp using
#define ak namespace
#define me std;
csp ak me
const int N=1e4+10,M=2e6+10;
//int h[N],e[M],ne[M],w[M],idx;
//void add(int a,int b,int c){
//	e[++idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx;
//}
#define int long long
int p[N];
int find(int x){
	if(x!=p[x]) p[x]=find(p[x]);
	return p[x];
}
struct Edge{
	int u,v,w;
	bool operator <(const Edge &x)const{
		return w<x.w;
	}
}g[M],g1[M];
int ans=LONG_LONG_MAX,n,m,k;
int c[20];
int a[20][N];
int kruskal(int m){
	int res=0,cnt=0;
	for(int i=1;i<=m;i++) g1[i]=g[i];
	sort(g1+1,g1+1+m);
//	for(int i=1;i<=m;i++) cout<<g1[i].u<<' '<<g1[i].v<<' '<<g1[i].w<<endl;
	for(int i=1;i<=k+n;i++) p[i]=i;
	for(int i=1;i<=m;i++){
		int u=g1[i].u,v=g1[i].v,w=g1[i].w;
		int pu=find(u),pv=find(v);
		if(pu==pv) continue;
		p[pu]=pv; cnt++; res+=w;
		if(cnt>=m-1) break;
	}
	return res;
}
bool vis[20];
//int cc=0;
void dfs(int x){
	if(x>k){
//		++cc;
		int sum=0,cnt=m;
//		for(int i=1;i<=k;i++) cout<<vis[i];
//		cout<<endl;
		for(int i=1;i<=k;i++){
			if(!vis[i]) continue;
			sum+=c[i];
//			cout<<cc<<endl;
			for(int j=1;j<=n;j++) g[++cnt]={n+i,j,a[i][j]};
		}
//		for(int i=1;i<=cnt;i++) cout<<g[i].u<<' '<<g[i].v<<' '<<g[i].w<<endl;
		sum+=kruskal(cnt);
//		cout<<sum<<endl;
		ans=min(ans,sum);
//		cout<<endl;
		return;
	}
	vis[x]=0;
	dfs(x+1);
	vis[x]=1;
	dfs(x+1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w; cin>>u>>v>>w;
		g[i]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	dfs(1);
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

