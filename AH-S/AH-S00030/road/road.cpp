#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+6;
inline ll read()
{
    char ch;
    ll s=0,f=1;
    ch=getchar();
    while (ch<'0'||ch>'9')
    {
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9')
    {
        s=s*10+(ch-'0');
        ch=getchar();
    }
    return s*f;
}
ll p[11000];
bool ins[11000],vis[11000];
struct edge
{
	ll next,to,fr,w;
}e[4*N];
ll head[N],cnt;
inline void add(ll u,ll v,ll w)
{
	cnt++;
	e[cnt].to=v;
	e[cnt].fr=u;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
ll n,m,k,d[N];
void dij(ll st)
{
	memset(d,0x3f,sizeof(d));
	priority_queue<pair<ll,ll> >q;
	q.push(make_pair(0,st));
	d[st]=0;
	while (!q.empty())
	{
		ll now=q.top().second;
		ll dis=d[now];
		q.pop();
		ins[now]=0;
		//cout<<now<<"   ";
		for (ll i=head[now];i;i=e[i].next)
		{
			
			ll to=e[i].to,w=e[i].w;
			//cout<<to<<' ';
			if (dis+w+p[to]<d[to])
			{
				d[to]=dis+w+p[to];
				if (!vis[to])
				{
					vis[to]=true;
					p[to]=0;
				}
				q.push(make_pair(d[to],to));
					ins[to]=true;
				/*if (!ins[to])
				{
					q.push(make_pair(d[to],to));
					ins[to]=true;
				}*/
				
			}
		}
		//cout<<endl;
	}
}
int main()
{
	freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for (ll i=1;i<=m;i++)
	{
		ll u,v,w;
		u=read();
		v=read();
		w=read();
		add(u,v,w);
		add(v,u,w);
	}
	for (ll i=1;i<=k;i++)
	{
		p[n+i]=read();
		for (ll j=1;j<=n;j++)
		{
			ll w;
			w=read();
			add(n+i,j,w);
			add(j,n+i,w);
		}
	}
	ll cnt=0;
	for (ll i=1;i<=k;i++)
	{
		cnt+=p[n+i];
	}
	if (cnt==0)
	{
		cout<<0;
		return 0;
	}
	dij(1);
	ll ans=-1;
	for (ll i=1;i<=n;i++)
	{
		//cout<<d[i]<<' ';
		ans+=d[i];
	}
	cout<<ans-n-k;
	return 0;
}
