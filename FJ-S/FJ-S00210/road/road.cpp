#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N_ 20005
#define P pair<ll,ll>
#define M_ 4000005
#define inf 10000000000000000
ll read()
{
	char ch=getchar();ll x=0,f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
ll n,m,k,ans=inf,a[20],V[M_],tot,edge[M_],dis[N_],head[N_],to[M_];
bool vis[20];
void add(ll u,ll v,ll w)
{V[++tot]=v;to[tot]=head[u];head[u]=tot;edge[tot]=w;}
priority_queue<P> p; 
bool h[N_];
void prim()
{
	memset(dis,0x3f,sizeof(dis));
	memset(h,0,sizeof(h));
	dis[1]=0;
	p.push({0,1});
	ll res=0;
		for(int i=1;i<=k;i++)
	if(vis[i])res+=a[i];
	while(p.size())
	{
		auto u=p.top();
		p.pop();
		if(h[u.second])continue;
		h[u.second]=1;
		res=-(u.first)+res;
		for(int i=head[u.second];i;i=to[i])
		{
			ll v=V[i];
			if(h[v])continue;
			if(v>n)
				if(!vis[v-n])continue;
			if(dis[v]>edge[i])
			dis[v]=edge[i],p.push({-(dis[v]),v}); 
		}
	}
	ans=min(ans,res); 
}
void clear()
{
	memset(vis,0,sizeof(vis));
 } 
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
	{
		ll u=read(),v=read(),w=read();
		add(u,v,w);add(v,u,w);
	}
	for(int i=1;i<=k;i++)
	{
		a[i]=read();
		for(int j=1;j<=n;j++)
		{
			ll w=read();
			add(j,i+n,w),add(i+n,j,w);
		}
	}
	for(int i=0;i<1<<k;i++)
	{	
 		clear();
		for(int j=0;j<k;j++)
		if(i>>j&1)vis[j+1]=1; 
		prim();
	}
	cout<<ans;
	return 0;
}

