#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <assert.h>
#define fin(f) freopen(f,"r",stdin)
#define fout(f) freopen(f,"w",stdout)
#define fo(i,l,r) for(int i=(l);i<=(r);i++)
#define of(i,r,l) for(int i=(r);i>=(l);i--)
#define debug cerr<<"["<<__LINE__<<"] "
#define pb push_back
#define endl '\n'
using namespace std;
typedef long long ll;
constexpr int inf=0x3f3f3f3f;
constexpr ll INF=0x3f3f3f3f3f3f3f3fll;
constexpr int M=1e6+5;
constexpr int K=15;
int n,m,k;
namespace Bruce {
	constexpr int N=1e3+5;
	ll a[N][N],b[N][N];
	struct Edge {
		int u,v;ll w;
	}e[M];
	ll co[K],c[K][N];
	ll dis[N];
	bool vis[N];
	ll prim() {
		fo(i,1,n) dis[i]=INF;
		fo(i,1,n) vis[i]=0;
		dis[1]=0;
		dis[0]=INF;
		ll ans=0;
		fo(i,1,n) {
			int u=0;
			fo(j,1,n) if(dis[u]>dis[j]&&!vis[j]) u=j;
			ans+=dis[u];
			vis[u]=1;
			fo(v,1,n) if(!vis[v]&&dis[v]>a[u][v])
				dis[v]=a[u][v];
		}
		return ans;
	}
	void solve1() {
		fo(i,1,k) {
			fo(x,1,n) fo(y,1,n) if(x!=y) a[x][y]=min(a[x][y],c[i][x]+c[i][y]);
		}
		cout<<prim()<<endl;
	}
	ll ans=INF;
	bool book[K];
//	int cnt=0;
	void dfs(int p) {
//		debug<<p<<endl;
		if(p>k) {
//			cnt++;
			fo(i,1,n) fo(j,1,n) a[i][j]=b[i][j];
			ll t=0;
			fo(i,1,k) if(book[i]) {
				t+=co[i];
				fo(x,1,n) fo(y,1,n) if(x!=y) a[x][y]=min(a[x][y],c[i][x]+c[i][y]);
			}
			ans=min(ans,prim()+t);
			return;
		}
		book[p]=1;
		dfs(p+1);
		book[p]=0;
		dfs(p+1);
	}
	void solve2() {
		fo(i,1,n) fo(j,1,n) b[i][j]=a[i][j];
		dfs(1);
//		debug<<1<<endl;
//		debug<<cnt<<endl;
		cout<<ans<<endl;
	}
	void work() {
		fo(i,1,n) fo(j,1,n) a[i][j]=INF;
		fo(i,1,n) a[i][i]=0;
		fo(i,1,m) {
			cin>>e[i].u>>e[i].v>>e[i].w;
			a[e[i].u][e[i].v]=min(a[e[i].u][e[i].v],e[i].w);
			a[e[i].v][e[i].u]=min(a[e[i].v][e[i].u],e[i].w);
		}
		bool p=0;
		fo(i,1,k) {
			cin>>co[i];
			p|=co[i];
			fo(j,1,n)
				cin>>c[i][j];
		}
		if(!p) solve1();
		else solve2();
	}
}
namespace Subtask {
	struct Edge {
		int u,v;ll w;
	}e[M];
	constexpr int N=1e4+5;
	int fa[N];
	void init() {
		fo(i,1,n) fa[i]=i;
	}
	int find(int x) {
		return fa[x]==x?x:(fa[x]=find(fa[x]));
	}
	void work() {
		fo(i,1,m) cin>>e[i].u>>e[i].v>>e[i].w;
		sort(e+1,e+m+1,[](Edge x,Edge y){return x.w<y.w;});
		init();
		int cnt=0;
		ll ans=0;
		fo(i,1,m) {
			if(cnt==n-1) break;
			int fx=find(e[i].u),fy=find(e[i].v);
			if(fx==fy) continue;
			fa[fx]=fy;
			ans+=e[i].w;
		}
		cout<<ans<<endl;
	}
}
int main() {
	fin("road.in");fout("road.out");
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>k;
	if(k) Bruce::work();
	else Subtask::work();
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

15
*/
