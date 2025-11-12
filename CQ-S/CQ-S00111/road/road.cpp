#include<bits/stdc++.h>

#define In(x) freopen(x,"r",stdin)
#define Out(x) freopen(x,"w",stdout)

#define int long long

using namespace std;

int n,m,k,cnt,tot;

const int N=2e4+5,M=2e6+5,S=15;

struct Edge{
	int x,y,w;
}e[M],ne[M];

int fa[N];

inline void Init(){
	for(int i=1;i<=n+k+1;i++) fa[i]=i;
}

inline int Find(int x){
	if(fa[x]==x) return x;
	return fa[x]=Find(fa[x]);
}

struct St{
	inline void Solve(){
		Init();
		sort(e+1,e+cnt+1,[](Edge x,Edge y){return x.w<y.w;});
		int ans=0;
		for(int i=1;i<=m;i++){
			int fx=Find(e[i].x),fy=Find(e[i].y);
			if(fx==fy) continue;
			fa[fx]=fy,ans+=e[i].w;
		}
		printf("%lld",ans);
	}
};

int c[S],g[S][N];

struct RI{
	inline void Solve(){
		Init();
		sort(e+1,e+cnt+1,[](Edge x,Edge y){return x.w<y.w;});
		int ans=0;
		for(int i=1;i<=cnt;i++){
			int fx=Find(e[i].x),fy=Find(e[i].y);
			if(fx==fy) continue;
			fa[fx]=fy,ans+=e[i].w;
			ne[++tot]=e[i];
		}
		for(int i=1;i<=tot;i++) e[i]=ne[i];
		int st=tot;
		for(int i=1;i<(1<<k);i++){
			int res=0;
			for(int j=0;j<k;j++) if(i>>j&1){
				for(int p=1;p<=n;p++) ne[++tot]=(Edge){j+n+1,p,g[j][p]};
				res+=c[j];
			}
			Init();
			sort(ne+1,ne+tot+1,[](Edge x,Edge y){return x.w<y.w;});
			for(int j=1;j<=tot;j++){
				int fx=Find(ne[j].x),fy=Find(ne[j].y);
				if(fx==fy) continue;
				fa[fx]=fy,res+=ne[j].w;
			}
			tot=st;
			for(int i=1;i<=tot;i++) ne[i]=e[i];
			ans=min(ans,res);
		}
		printf("%lld",ans);
	}
};

signed main()
{
	In("road.in");Out("road.out");
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1,a,b,w;i<=m;i++){
		scanf("%d%d%d",&a,&b,&w);
		e[++cnt]=(Edge){a,b,w};
	}
	for(int i=0;i<k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++) scanf("%lld",&g[i][j]);
	}
	if(k==0) (new St)->Solve();
	else (new RI)->Solve();
	return 0;
}

