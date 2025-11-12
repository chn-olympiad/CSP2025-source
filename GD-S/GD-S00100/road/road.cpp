#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define N (int)(1e4+20)
#define M (int)(1e6+10)

int n,m,k;

struct edge{
	int nxt,to,frm;
	ll w;
}e[M<<1];

int hd[N],cnt;
int hd2[N],cnt2;

int f[N];

ll awa[12];
ll qwq[12][N];

bool vis[12];

inline void add(int u,int v,ll w){
	e[++cnt].to=v;
	e[cnt].w=w;
	e[cnt].frm=u;
	e[cnt].nxt=hd[u];
	hd[u]=cnt;
}

inline bool cmp(edge x,edge y){
	return x.w<y.w;
}
int find(int x){
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;++i){
		int u,v;
		ll w;
		scanf("%d %d %lld",&u,&v,&w);
		add(u,v,w);
	}
	for(int i=1;i<=k;++i){
		scanf("%lld",&awa[i]);
		for(int j=1;j<=n;++j){
			scanf("%lld",&qwq[i][j]);
			add(n+i,j,qwq[i][j]);
		}
	}
	for(int i=1;i<=n+k;++i) f[i]=i;
	sort(e+1,e+cnt+1,cmp);
	ll ans=0;
	for(int i=1;i<=cnt;++i){
		int x=e[i].frm,y=e[i].to;
		int fx=find(x),fy=find(y);
		if(fx!=fy){
			f[fy]=fx;
			if(x>y) swap(x,y);
			if(y>n&&!vis[y]) ans+=awa[y],vis[y]=1;
			ans+=e[i].w;
		}
	}
	printf("%lld\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
} 
