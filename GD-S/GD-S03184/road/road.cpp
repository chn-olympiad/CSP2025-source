#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e4+12,M=1e6+10,Maxn=LONG_LONG_MAX;
ll n,m,k,b[N];
struct node{
	ll w,to,nxt;
};

ll jz[12][N];

node ed[2*M];
ll top=0,head[N];
void add(ll u,ll v,ll w)
{
	ed[++top].to=v;
	ed[top].w=w;
	ed[top].nxt=head[u];
	head[u]=top;
}
ll d[N],dis[N],ans;
bool bj[N];
void solve0()
{
	//×î¶ÌÂ·
	for(ll i=2;i<=n;i++)
	  d[i]=Maxn;
	queue <ll>q;
	q.push(1);
	bj[1]=true;
	while(!q.empty())
	{
		ll u=q.front();
		q.pop();
		for(ll i=head[u];i;i=ed[i].nxt)
		{
			ll to=ed[i].to;
			if(d[u]+ed[i].w<d[to])
			{
				d[to]=d[u]+ed[i].w;
			}
			if(bj[to]) continue;
			bj[to]=true;
			q.push(to); 
		}
	}
	q.push(1);
	bj[1]=false;
	while(!q.empty())
	{
		ll u=q.front();
		q.pop();
		for(ll i=head[u];i;i=ed[i].nxt)
		{
			ll to=ed[i].to;
			if(d[to]==d[u]+ed[i].w)
			{
				ans+=ed[i].w;
				q.push(to);
			}
		}
	}
	printf("%lld",ans);
}
void solve1()
{
	for(ll i=1;i<=k;i++)
	{
		for(ll j=1;j<=n;j++)
		if(jz[i][j]==0)
		{
			for(ll to=1;to<=n;to++)
			if(to!=j)
			{
				add(j,to,jz[i][to]);
				add(to,j,jz[i][to]);
			}
		}
	}
	solve0();
}
bool fb[11];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	bool fa=true;
	for(ll i=1;i<=m;i++)
	{
		ll u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	for(ll i=1;i<=k;i++)
	{
		scanf("%lld",&b[i]);
		for(ll j=1;j<=n;j++)
		{
			ll w;
			scanf("%lld",&w);
			jz[i][j]=w;
			if(w==0) fb[i]=true;
		}
		if(b[i]!=0) fa=false;
	}
	for(ll i=1;i<=k;i++) if(!fb) fa=false;
	if(k==0)
	  solve0();
	else
	  solve1();
	return 0;
}
