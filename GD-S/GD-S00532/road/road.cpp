#include<bits/stdc++.h>
#define FL(i,a,b) for(int i=(a);i<=(b);i++)
#define FR(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long
#define ull unsigned long long
#define ld long double
#define PII pair<ll,ll> 
using namespace std;
const int MAXN = 1e4 + 30;
const int MAXM = 1e6 + 10;
const int MAXK = 10 + 5;
const int inf = 0x3f3f3f3f;

int n,m,K,U,cnt=0;
ll sum=0,ans=0;
int fa[MAXN];
vector<PII>G[MAXN];
int c[MAXK],a[MAXK][MAXN];
int dis[MAXN];
bool vis[MAXN],A=1;
priority_queue<PII>q;

struct Edge{
	int u,v,w;
}e[MAXM],E[MAXM];

bool cmp(Edge p,Edge q){
	return p.w<q.w;
}

int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

void kruskal(){
	sort(e+1,e+m+1,cmp);
	FL(i,1,n) fa[i]=i;
	FL(i,1,m){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)==find(v)) continue;
		e[++cnt]=e[i];
		G[u].push_back({v,w});
		G[v].push_back({u,w});
		fa[find(u)]=find(v);
		sum+=w;
	}
	m=cnt;
}

ll prim(int S){
	ll res=0;
	FL(i,1,n+K) vis[i]=0,dis[i]=inf;
	FL(i,1,K) if(!(S&(1<<i-1))) vis[n+i]=1;
//	FL(i,1,n) printf("dis[%lld]=%lld\n",i,dis[i]);
	dis[1]=0;
	q.push({0,1});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue; 
		vis[u]=1;
//		printf("u=%lld,dis=%lld\n",u,dis[u]);
		res+=dis[u],dis[u]=0;
		if(u>n){
			FL(i,1,n)
				if(!vis[i]&&dis[i]>a[u-n][i]) dis[i]=a[u-n][i],q.push({-dis[i],i});
			continue;
		}
		for(auto i:G[u]){
			int v=i.first,w=i.second;
			if(!vis[v]&&dis[v]>w) dis[v]=w,q.push({-dis[v],v});
		}
		FL(i,1,K)
			if(!vis[n+i]&&dis[n+i]>a[i][u]) dis[n+i]=a[i][u],q.push({-dis[n+i],n+i});
	}
	return res;
}

ll kruskal(int S){
	ll res=0;
	cnt=m;
	FL(i,1,m) E[i]=e[i];
	FL(i,1,n+K) vis[i]=0,dis[i]=inf,fa[i]=i;
	FL(i,1,K){
		if(!(S&(1<<i-1))) continue;
		int id=1;
		FL(j,2,n) if(a[i][j]<a[i][id]) id=j;
		res+=a[i][id];
		fa[find(id)]=n+i;
		FL(j,1,n) if(j!=id) E[++cnt]={n+i,j,a[i][j]};
	}
//	FL(i,1,cnt) printf("%d %d %d\n",E[i].u,E[i].v,E[i].w);
//	FL(i,1,K) if(!(S&(1<<i-1))) vis[n+i]=1;
//	FL(i,1,n) printf("dis[%lld]=%lld\n",i,dis[i]);
	sort(E+1,E+cnt+1,cmp);
	FL(i,1,cnt){
		int u=E[i].u,v=E[i].v,w=E[i].w;
//		printf("(%d,%d,%d)\n",u,v,w);
		if(find(u)==find(v)) continue;
		fa[find(u)]=find(v);
		res+=w;
	}
	return res;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	freopen("road3.in","r",stdin);
//	freopen("road.txt","w",stdout);
	scanf("%d%d%d",&n,&m,&K),U=(1<<K)-1;
	FL(i,1,m)
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	FL(i,1,K){
		scanf("%d",&c[i]);
		bool fg=0;
		FL(j,1,n) scanf("%d",&a[i][j]),fg|=(a[i][j]==0);
//		FL(j,1,n) if(a[i][j]==0) printf("%d %d\n",i,j);
		A&=(c[i]==0&&fg);
	}
	kruskal();
	ans=sum;
//	FL(i,1,m){
//		G[e[i].u].push_back({e[i].v,e[i].w});
//		G[e[i].v].push_back({e[i].u,e[i].w});
//	}
	if(A){
//		puts("A");
		ans=min(ans,kruskal(U));
		printf("%lld\n",ans);
		exit(0);
	}
	FL(S,1,U){
		ll now=0;
		FL(i,1,K) if(S&(1<<i-1)) now+=c[i];
		ans=min(ans,prim(S)+now);
	}
	printf("%lld\n",ans);
}
