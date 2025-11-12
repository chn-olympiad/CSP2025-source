#include<bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define rep(i,l,r) for(int i=(l); i<=(r); ++i)
#define drep(i,r,l) for(int i=(r); i>=(l); --i)
using namespace std;
#define LL long long
const int N=2e4+50;
int n,m,k,K,t[N],c[N],v,A[10][N],fa[N],F[N],G[1<<10][N];
LL ret;
struct Node {
	int u,v,w;
	inline bool operator<(const Node&o) const {return w<o.w;}
} E[N*100];
inline int find(int u) {return u==fa[u]?u:fa[u]=find(fa[u]);}
inline LL sol(int S,int T,int id,LL ret=0) {
	iota(fa,fa+N,0);
	int o=0;
	rep(i,1,t[T]) F[++o]=G[T][i];
	rep(i,0,k-1) if(S>>i&1) ret+=c[i];
	rep(i,1,n) F[++o]=A[id][i];
	sort(F+1,F+o+1,[](const int&u,const int&v) {return E[u]<E[v];});
	rep(i,1,o) {
		int u=find(E[F[i]].u),v=find(E[F[i]].v);
		if(u^v) G[S][++t[S]]=F[i],fa[u]=v,ret+=E[F[i]].w;
	}
	return ret;
}
signed main() {
	FASTIO;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k,K=m,iota(fa,fa+N,0);
	rep(i,1,m) cin>>E[i].u>>E[i].v>>E[i].w;
	rep(i,0,k-1) {
		cin>>c[i];
		rep(j,1,n) cin>>v,E[++K]={i+n+1,j,v},A[i][j]=K;
	}
	sort(E+1,E+m+1);
	rep(i,1,m) {
		int u=find(E[i].u),v=find(E[i].v);
		if(u^v) G[0][++t[0]]=i,fa[u]=v,ret+=E[i].w;
	}
	rep(S,0,(1<<k)-1) rep(i,0,k-1) if(S>>i&1^1&&!t[S|1<<i]) ret=min(ret,sol(S|1<<i,S,i));
	cout<<ret<<'\n';
}
