#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=1e5+5,M=1e6+5,K=15;
struct edge
{
	ll u,v,w;
}e[M<<2];
ll n,m,k,h[N],ne[M<<1],to[M<<1],wp[M<<1],t,c[K],a[K][N],fa[N],s[N],ans,p;
void add(ll x,ll y,ll z,ll o)
{
	ne[o]=h[x];
	to[o]=y;
	wp[o]=z;
	h[x]=o;
}
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
ll find(ll x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	p=n;
	for(ll i=1;i<=n+k;i++)
	{
		fa[i]=i;
		if(i<=n)
		{
			s[i]=1;
		}
	}
	for(ll i=1;i<=m;i++)
	{
		ll x,y,z;
		cin>>x>>y>>z;
		e[++t].u=x;
		e[t].v=y;
		e[t].w=z;
	}
	for(ll i=1;i<=k;i++)
	{
		cin>>c[k];
		bool fl=0;
		for(ll j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(!a[i][j])
			{
				fl=1;
			}
		}
		if(!c[k]&&fl)
		{
			for(ll j=1;j<=n;j++)
			{
				e[++t].u=n+i;
				e[t].v=j;
				e[t].w=a[i][j];
				s[n+i]=1;
				p++;
			}
		}
	}
	sort(e+1,e+t+1,cmp);
	for(ll i=1;i<=t;i++)
	{
		ll x=find(e[i].u),y=find(e[i].v);
		if(x!=y)
		{
			if(s[x]<s[y])
			{
				swap(x,y);
			}
			s[x]+=s[y];
			fa[y]=x;
			ans+=e[i].w;
			if(s[x]==p)
			{
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
