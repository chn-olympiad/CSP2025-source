#include<bits/stdc++.h>
#define ll long long
#define bint __int128
#define pb push_back
#define mkp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define chkmin(a,b) a=min(a,b)
#define debug(x) cout<<#x<<" = "<<x<<endl
using namespace std;
const ll mod=998244353;
inline ll fpow(ll a,ll b){
	ll res=1;
	for(;b;b>>=1,a=a*a%mod)if(b&1)res=res*a%mod;
	return res;
}
const int N=2e5+5,M=1e6+1e5+5;
const ll inf = 1e18;
int n,m,k,idx;
struct Edge{
	int u,v,w,t;
	void init(int _u,int _v,int _w,int _t){u=_u,v=_v,w=_w,t=_t;}
	bool operator<(const Edge& t)const{
		return w<t.w;
	}
}e[M];
int c[15],seq[15],tot;
int fa[N+15];
int Deg[N+15];
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
bool merge(int u,int v){
	u=find(u),v=find(v);
	if(u==v)return 0;
	fa[u]=v;
	Deg[u]++,Deg[v]++;
	return 1;
}
ll res=inf,now=0;
void Kruskal(int S){
	for(int i=1;i<=n+k;i++)fa[i]=i;
	int t=n+__builtin_popcount(S);
	for(int i=1;i<=idx;i++){
		if(e[i].t && (!(S>>(e[i].t-1)&1)))continue;
		if(merge(e[i].u,e[i].v))now+=e[i].w,t--;
		if(now>=res)return ;
		if(t==1)return ;
	}
	return ;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[++idx].init(u,v,w,0);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int w; cin>>w;
			e[++idx].init(n+i,j,w,i);
		}
	}
	sort(e+1,e+1+k*n+m);
	for(int s=0;s<(1<<k);s++){
		now=0;
		for(int j=0;j<k;j++)if(s>>j&1)now+=c[j+1];
		Kruskal(s);
		chkmin(res,now);
	}
	cout<<res;
	return 0;
}
//  我咋不会 T2 阿
//  写个 2^km 跑路了
