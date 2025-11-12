#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e4+5,M=1e6+5;
ll res=1e18,f[N],c[N],w[15][N];
struct node{ll u,v,w;}a[M+30*N];
bool cmp(node a,node b){return a.w<b.w;}
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
ll P[N],B[N],vis[N],in[N],tp[N],cur[N],mn[15][N],nxt[15][N];//在k这个状态下，连上其他点的最短路径 
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k;
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n+k+1;i++)f[i]=i;
	if(k==0)
	{
		ll ans=0;
		for(int i=1;i<=m;i++)scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
		for(int i=0;i<k;i++)
		{
			scanf("%lld",&c[i]);
			for(int j=1;j<=n;j++)scanf("%lld",&w[i][j]);
		}
		sort(a+1,a+1+m,cmp);
		for(int i=1;i<=m;i++)
		{
			int x=find(a[i].u);
			int y=find(a[i].v);
			if(x!=y)f[x]=y,ans+=a[i].w;
		}
		printf("%lld\n",ans);
	}
	else if((1<<k)*(k*n+(m+n*k)*25)<=100000000)
	{
		for(int i=1;i<=m;i++)scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
		for(int i=0;i<k;i++)
		{
			scanf("%lld",&c[i]);
			for(int j=1;j<=n;j++)scanf("%lld",&w[i][j]);
		}
		for(int s=0;s<(1<<k);s++)
		{
			ll pos=m,ans=0;
			for(int i=0;i<k;i++)
			{
				if(s&(1<<i))
				{
					ans+=c[i];
					for(int j=1;j<=n;j++)a[++pos]={i+n+1,j,w[i][j]};
				}
			}
			for(int i=1;i<=n+k+1;i++)f[i]=i;
			sort(a+1,a+1+pos,cmp);
			for(int i=1;i<=pos;i++)
			{
				int x=find(a[i].u);
				int y=find(a[i].v);
				if(x!=y)f[x]=y,ans+=a[i].w;
			}
			res=min(res,ans);
		}
		printf("%lld\n",res);
	}
	else
	{
		for(ll i=1;i<=m;i++)scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
		for(ll i=0;i<k;i++)
		{
			scanf("%lld",&c[i]);
			ll mi1=1e18,mi2=1e18,pi1=0,pi2=0;
			for(ll j=1;j<=n;j++)
			{
				scanf("%lld",&w[i][j]);
				if(mi1>w[i][j])mi2=mi1,mi1=w[i][j],pi2=pi1,pi1=j;
				else if(mi2>w[i][j])mi2=w[i][j],pi2=j;
			}
			for(ll j=1;j<=n;j++)
			{
				if(w[i][j]==mi1)mn[i][j]=mi1+mi2,nxt[i][j]=pi2;
				else if(w[i][j]==mi2)mn[i][j]=mi1+mi2,nxt[i][j]=pi1;
				else mn[i][j]=w[i][j]+mi1,nxt[i][j]=pi1;
			}
		}
		ll mst=0;
		sort(a+1,a+1+m,cmp);
		for(ll i=1;i<=m;i++)
		{
			ll x=find(a[i].u);
			ll y=find(a[i].v);
			if(x!=y)f[x]=y,mst+=a[i].w,B[a[i].u]+=a[i].w,in[a[i].u]++,in[a[i].v]++;
		}
		for(ll s=0;s<(1<<k);s++)
		{
			ll ans=mst;
			for(ll i=1;i<=n;i++)P[i]=1e18,vis[i]=cur[i]=0;
			for(ll i=0;i<k;i++)
			{
				if(s&(1<<i))
				{
					ans+=c[i];
					for(ll j=1;j<=n;j++)
					{
						if(in[j]==1&&mn[i][j]<B[j])
						{
							P[j]=min(P[j],mn[i][j]);
							cur[j]=i;
						}
					}
				}
			}
			for(ll i=1;i<=n;i++)if(P[i]!=1e18&&!vis[i])ans-=B[i]-P[i],vis[nxt[cur[i]][i]]=1;
			res=min(res,ans);
		}
		printf("%lld\n",res);
	}
	return 0;
}
