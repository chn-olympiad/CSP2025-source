#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define faster ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0)
struct _
{
	ll u,v,w;
	bool operator<(_ ot)
	{
		return w<ot.w;
	}
}e[1100006];
ll fa[20004];
ll find(ll x)
{
	if (x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
ll kruskal(ll n,ll m)
{
	for (ll i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	ll res=0;
	for (ll i=1;i<=m;i++)
	{
		ll fu=find(e[i].u),fv=find(e[i].v);
		if (fu==fv)continue;
		fa[fu]=fv;
		res+=e[i].w;
	}
	return res;
}
ll n,m,k,c[15],ans=1e18;
_ en[1100006],ek[15][10004];
void add(basic_string<ll>v)
{
	ll p[15];
	p[0]=1;
	for (ll i=0;i<v.size();i++)
	{
		p[v[i]]=1;
	}
	for (ll i=1;i<=m+n*v.size();i++)
	{
		_ mn;
		if (p[0]<=m)mn=en[p[0]];
		else mn={-1,-1,(ll)1e18};
		ll aa=0;
		for (ll j=0;j<v.size();j++)
		{
			if (p[v[j]]<=n&&ek[v[j]][p[v[j]]]<mn)
			{
				mn=ek[v[j]][p[v[j]]];
				aa=v[j];
			}
		}
		e[i]=mn;
		p[aa]++;
	}
}
int main()
{
	faster;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	bool A=1;
	cin>>n>>m>>k;
	for (ll i=1;i<=m;i++)
	{
		ll u,v,w;
		cin>>u>>v>>w;
		en[i]={u,v,w};
	}
	sort(en+1,en+1+m);
	for (ll i=1;i<=k;i++)
	{
		cin>>c[i];
		if (c[i])A=0;
		for (ll j=1;j<=n;j++)
		{
			ll u=n+i,v=j,w;
			cin>>w;
			ek[i][j]={u,v,w};
		}
		sort(ek[i]+1,ek[i]+1+n);
	}
	if (A)
	{
		ll i=(1<<k)-1;
		basic_string<ll>v;
		v.clear();
		v.shrink_to_fit();
		ll cnt=m,res=0;
		for (ll j=0;j<k;j++)
		{
			if (i&(1<<j))
			{
				v.pb(j+1);
				cnt+=n;
				res+=c[j+1];
			}
		}
		add(v);
		ans=min(ans,res+kruskal(n+k,cnt));
		cout<<ans;
		return 0;
	}
	for (ll i=0;i<(1<<k);i++)
	{
		basic_string<ll>v;
		v.clear();
		v.shrink_to_fit();
		ll cnt=m,res=0;
		for (ll j=0;j<k;j++)
		{
			if (i&(1<<j))
			{
				v.pb(j+1);
				cnt+=n;
				res+=c[j+1];
			}
		}
		add(v);
		ans=min(ans,res+kruskal(n+k,cnt));
	}
	cout<<ans;
	return 0;
}//72
