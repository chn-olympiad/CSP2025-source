#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define mkp make_pair
#define eb emplace_back
#define pb push_back
const int N=1e4+20,M=1e6+5,maxk=12;
const ll inf=1e15+38;
int n,m,k;
ll a[maxk][N],g[maxk][N],val[maxk];
ll dp[N];
struct Edge{int to,w;bool operator < (const Edge oth)const{return w<oth.w;}};
struct edg{int u,v,w;bool operator < (const edg oth)const{return w<oth.w;}}ed[M];
vector<Edge> G[N];
namespace DSU{
	int fa[N];
	void ini(int x){for(int i=1;i<=x;i++) fa[i]=i;}
	int fd(int x){return (x==fa[x]?x:fa[x]=fd(fa[x]));}
	bool mge(int x,int y){x=fd(x),y=fd(y);if(x==y) return 0;fa[x]=y;return 1;}
}using namespace DSU;
void dfs(int u,int fa){
	sort(G[u].begin(),G[u].end());
	for(Edge nw:G[u]){
		int v=nw.to,w=nw.w;
		if(v==fa) continue;
		dfs(v,u);
	}
	for(Edge nw:G[u]){
		int v=nw.to,w=nw.w;
		if(v==fa) continue;
		for(int o=1;o<=k;o++) g[o][u]=min(g[o][u],g[o][v]);
		if(fd(v)==fd(u)) continue;
		ll re1=inf,re2=inf;
		int po1=0,po2=0;
		for(int o=1;o<=k;o++){
			if(fd(o+n)==fd(v)) re1=min(re1,a[o][u]),po1=(re1==a[o][u]?o:po1);
			else if(fd(o+n)==fd(u)) re1=min(re1,g[o][v]),po1=(re1==g[o][v]?o:po1); 
			else re2=min(re2,val[o]+a[o][u]+g[o][v]),po2=(re2==val[o]+a[o][u]+g[o][v]?o:po2);
		}
		int res=min((ll)w,min(re1,re2));
		dp[u]+=res+dp[v];
		if(res==w){mge(u,v);}
		else if(res==re1){mge(u,po1+n),mge(v,po1+n);}
		else mge(v,po2+n),mge(u,po2+n);
	} 
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		ed[i]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>val[i];
		for(int j=1;j<=n;j++) cin>>a[i][j],g[i][j]=a[i][j];
	}
	sort(ed+1,ed+m+1);
	int tot=0;ll qwq=0;
	ini(n);
	for(int i=1;i<=m&&tot<n-1;i++){
		int u=ed[i].u,v=ed[i].v,w=ed[i].w;
		if(mge(u,v)){
			tot++;qwq+=w;
			G[u].pb((Edge){v,w});G[v].pb((Edge){u,w});
		}
	} 
	if(!k){cout<<qwq<<'\n';return 0;}
	ini(n+k);
	dfs(1,0);
	cout<<dp[1]<<'\n';
	return 0;
}

