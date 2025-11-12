#include <bits/stdc++.h>
#define FILE(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define endl '\n'
#define mem(a,v) memset(a,v,sizeof(a))
#define pll pair<long long,long long>
#define pii pair<int,int>
#define st first
#define nd second
#define pb push_back
#define mkp make_pair
//#define int long long
using namespace std;
using ll=long long;
using lld=long double;
const int N=1e4+10,M=2e6+10,K=15;
int n,m,k;
ll ans,c[K],a[K][N];
//struct edge{int v;ll w;};
//vector<edge>g[N];
struct EDGE{int u,v;ll w;}e[M];
bool cmp(EDGE a,EDGE b){return a.w<b.w;}
int fa[N];
int Find(int x){
	return (fa[x]==x?x:fa[x]=Find(fa[x]));
}
void Merge(int x,int y){
	int fx=Find(x),fy=Find(y);
	if(fx!=fy)fa[fx]=fy;
}
void Kruscal(){
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(e+1,e+m+1,cmp);
	for(int cnt=0,i=1;cnt<n-1&&i<=m;i++)
		if(Find(e[i].u)!=Find(e[i].v))
			cnt++,ans+=e[i].w,Merge(e[i].u,e[i].v);
}
signed main(){
	FILE("road");
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
//		g[u].pb({v,w}),g[v].pb({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
		for(int j=1;j<=n;j++)if(a[i][j]==0){
			for(int p=1;p<=n;p++)if(p!=j)
//				g[j].pb(p,a[i][p]),g[p].pb(j,a[i][p]),
				e[++m]={j,p,a[i][p]};
			break;
		}
	}
	Kruscal(),cout<<ans;
	return 0;
}

