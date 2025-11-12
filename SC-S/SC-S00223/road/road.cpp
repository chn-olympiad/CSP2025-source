#include<bits/stdc++.h>
#define ll long long
#define INF 214748364719260817ll
using namespace std;
ll n,m,k;
struct ed
{
	ll u,v,w;
	bool operator<(const ed&b)const
	{
		return w<b.w;
	}
}a[1000005],e[10005],c[10][10005];
ll w[10];
ll cot;
ll f[10015];
ll find(ll x)
{
	return x==f[x]?x:f[x]=find(f[x]);
}
ll nr[10];
int main()
{
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;++i)cin>>a[i].u>>a[i].v>>a[i].w;
	sort(a+1,a+1+m);
	for(ll i=1;i<=n;++i)f[i]=i;
	ll sum=0;
	for(ll i=1;i<=m;++i)
	{
		ll un=find(a[i].u),vn=find(a[i].v);
		if(un!=vn)
		sum+=a[i].w,f[un]=vn,e[++cot]=a[i];
	}
	for(ll i=0;i<k;++i)
	{
		cin>>w[i];
		for(ll j=1;j<=n;++j)cin>>c[i][j].w,c[i][j].v=i+1+n,c[i][j].u=j;
		sort(c[i]+1,c[i]+1+n);
	}
	ll res=sum;
	for(ll i=1;i<(1<<k);++i)
	{
		vector<ll>use;
		ll es=n-1,cost=0;
		for(ll j=0;j<k;++j)
			if((i>>j)&1)
			use.emplace_back(j),nr[j]=1,f[j+n+1]=j+n+1,++es,cost+=w[j];
		for(ll j=1;j<=n;++j)f[j]=j;
		ll rs=1;
		while(es--)
		{
			ed minn;
			minn.w=INF;
			for(auto it:use)
			{
				while(nr[it]<=n&&find(c[it][nr[it]].u)==find(c[it][nr[it]].v))++nr[it];
				if(nr[it]<=n)minn=min(minn,c[it][nr[it]]);	
			}
			while(rs<=cot&&find(e[rs].u)==find(e[rs].v))++rs;
			if(rs<=cot)minn=min(minn,e[rs]);
			f[find(minn.u)]=find(minn.v);
			cost+=minn.w;
			if(cost>=res)break;
		}
		res=min(res,cost);
	}
	cout<<res;
}//先跑一次生成树，保留 n-1 条边，只有这些有用 