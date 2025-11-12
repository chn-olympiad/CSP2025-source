#include<bits/stdc++.h>

using namespace std;
bool Mbe;

using i64=long long;

constexpr int maxn=1e4+30,maxm=1e6+10,maxk=10;
constexpr i64 inf=2e18;

int n,m,k;

struct EDGE{
	int u,v,w;
	bool operator<(const EDGE &x) const{
		return w<x.w;
	}
};
struct DSU{
	int fa[maxn];
	
	int findf(int u){
		return u==fa[u]?u:fa[u]=findf(fa[u]);
	}
};

struct E{
	DSU d;
	EDGE e[maxn];
	int e_cnt;
	i64 res;
}a[1<<maxk];

int tot;
EDGE b[maxm];

int c[maxk+10];

int e_k[maxk+10][maxn];
int Lg[1<<maxk];

void merge(int s,int t,int id){
	tot=0;
	for(int i=1;i<=a[t].e_cnt;++i) b[++tot]=a[t].e[i];
	for(int i=1;i<=n;++i){
		int u=id+n,v=i,w=e_k[id][i];
		b[++tot]=(EDGE){u,v,w};
	}
	for(int i=1;i<=n+k;++i) a[s].d.fa[i]=i;
	
	sort(b+1,b+tot+1);
	
	int cnt=0;
	for(int i=1;i<=tot;++i){
		int u=b[i].u,v=b[i].v,w=b[i].w;//if(s==1) cerr<<u<<' '<<v<<' '<<w<<'\n';
		if(a[s].d.findf(u)==a[s].d.findf(v)) continue;
		a[s].d.fa[a[s].d.findf(u)]=a[s].d.findf(v);
		a[s].res+=w;
		a[s].e[++cnt]=b[i];
//		if(s==1) cerr<<u<<' '<<v<<' '<<w<<'\n';
	}
	a[s].e_cnt=cnt;
	
//	if(s==1) cerr<<a[s].res<<'\n';
	
	for(int i=1;i<=k;++i) if((s>>(i-1))&1) a[s].res+=c[i];
}

bool Med;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	
//	freopen("road4.in","r",stdin);
//	freopen("roadmy.out","w",stdout);
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	
	for(int i=1;i<=m;++i) cin>>b[i].u>>b[i].v>>b[i].w;
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j) cin>>e_k[i][j];
	}
	
	sort(b+1,b+m+1);
	for(int i=1;i<=n;++i) a[0].d.fa[i]=i;
	for(int i=1;i<=m;++i){
		int u=b[i].u,v=b[i].v,w=b[i].w;
		if(a[0].d.findf(u)==a[0].d.findf(v)) continue;
		a[0].d.fa[a[0].d.findf(u)]=a[0].d.findf(v);a[0].res+=w;
		a[0].e[++tot]=b[i];
	}
	a[0].e_cnt=tot;
	tot=0;
//	cerr<<a[0].res<<'\n';
	
	for(int i=1;i<=k;++i) Lg[1<<(i-1)]=i;
	for(int s=1;s<(1<<k);++s) merge(s,s-(s&(-s)),Lg[s&(-s)]);
	
//	cerr<<a[1].res<<'\n';
	
	i64 ans=inf;
	for(int s=0;s<(1<<k);++s) ans=min(ans,a[s].res);
	
	cout<<ans<<'\n';
	
	cerr<<'\n'<<fabs(&Med-&Mbe)/1048576.0<<"MB\n";
	cerr<<'\n'<<1e3*clock()/CLOCKS_PER_SEC<<"ms\n";
	return 0;
}