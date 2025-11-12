#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+5,M=1e6+5,K=15;
const ll INF=0x3f3f3f3f3f3f3f3f;
int n,m,k,tot,c[K],fa[N+K];
bool vis[N];
ll ans,lim;
struct Edge
{
	int u,v,w;
}e[M+K*N];
int find(int x)
{
	return fa[x]^x?fa[x]=find(fa[x]):x;
}
ll Kruskal()
{
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(e+1,e+1+n,[](Edge a,Edge b){return a.w<b.w;});
	int cnt=1; ll res=0;
	for(int i=1;i<=tot;i++)
	{
		int u=find(e[i].u),v=find(e[i].v),w=e[i].w;
		if(u==v) continue;
		res+=w;
		if(++cnt==n) break;
	}
	return res;
}
void solve(int now,int cnt_used,ll cost)
{
	if(now>k)
	{
		for(int i=1;i<N+K;i++) fa[i]=i;
		int cnt=1; ll res=cost;
		for(int i=1;i<=tot;i++)
		{
			if(e[i].u>n&&!vis[e[i].u-n]) continue;
			int u=find(e[i].u),v=find(e[i].v),w=e[i].w;
			if(u==v) continue;
			fa[u]=v,res+=w;
			if(++cnt==n+cnt_used) break;
		}
		return ans=min(ans,res),void();
	}
	if(cost+c[now]<=lim)
	{
		vis[now]=true;
		solve(now+1,cnt_used+1,cost+c[now]);	
	}
	vis[now]=false;
	solve(now+1,cnt_used,cost);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k),tot=m;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	ans=lim=Kruskal();
	int subA=0;
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]),subA+=(!c[i]);
		for(int j=1;j<=n;j++)
		{
			int w;
			scanf("%d",&w),subA+=(!w);
			e[++tot]=(Edge){n+i,j,w};
		}
	}
	if(subA==k*(n+1)) return puts("0"),0;
	sort(e+1,e+1+tot,[](Edge a,Edge b){return a.w<b.w;});
	solve(1,0,0);
	printf("%lld",ans);
	return 0;
}
