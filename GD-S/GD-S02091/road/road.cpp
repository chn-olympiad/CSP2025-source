#include <cstdio>
#include <algorithm>

using namespace std;

const int N=11451,inf=1e9+7;

namespace U{
	int anc[N],siz[N];
	void iit(int n){for(int i=1;i<=n;++i) anc[i]=i,siz[i]=1;}
	int fnd(int x){return anc[x]==x?x:anc[x]=fnd(anc[x]);}
	void mrg(int x,int y){
		x=fnd(x);y=fnd(y);if(siz[x]>siz[y]) swap(x,y);
		anc[x]=y;siz[y]+=siz[x];
	}
}

struct ed{int x,y,w;bool operator<(const ed &t)const{return w<t.w;};}V[1048576],a[11][N];

bool ch[11]={1};int c[11],p[11],K,n;long long ans;

void dfs(int k){
	if(k>K){
		U::iit(n+K);long long S=0;int T=0;
		for(int i=1;i<=K;++i) if(ch[i]) S+=c[i],++T;
		if(!T) return ;
		for(int r=1;r<n+T;){int nx,W=inf;
			for(int i=0;i<=K;++i) if(ch[i]&&a[i][p[i]+1].w<W) nx=i,W=a[i][p[i]+1].w;
			ed E=a[nx][++p[nx]];
			if(U::fnd(E.x)!=U::fnd(E.y)) U::mrg(E.x,E.y),S+=E.w,++r;
		}
		ans=min(ans,S);
		for(int i=0;i<=K;++i) p[i]=0;
		return ;
	}
	ch[k]=1;dfs(k+1);ch[k]=0;dfs(k+1);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m,m0=0;scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=m;++i) scanf("%d%d%d",&V[i].x,&V[i].y,&V[i].w);
	sort(V+1,V+m+1);U::iit(n);
	for(int i=1;i<=m&&m0<n-1;++i) if(U::fnd(V[i].x)!=U::fnd(V[i].y))
		a[0][++m0]=V[i],U::mrg(V[i].x,V[i].y),ans+=V[i].w;
	for(int k=1;k<=K;++k){
		scanf("%d",c+k);for(int i=1;i<=n;++i) scanf("%d",&a[k][i].w),a[k][i].x=i,a[k][i].y=n+k;
		sort(a[k]+1,a[k]+n+1);
	}
	a[0][m0+1].w=inf;for(int i=1;i<=K;++i) a[i][n+1].w=inf;
	dfs(1);printf("%lld",ans);
}
