#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll M=1e4+5,N=1e6+5,KK=15;
ll n,m,k,cnt,f[10015],c[KK],Min=LLONG_MAX;
struct edge
{
	ll u,v,w,op;
	bool operator < (edge& x) const
	{
		return w<x.w;
	}
}e[2200005];
void add(ll u,ll v,ll w,ll op)
{
	e[++cnt]={u,v,w,op};
}
bool f2[KK],f3[10015];
ll fg(ll x)
{
	return x==f[x]?x:f[x]=fg(f[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		ll u,v,w;
		cin>>u>>v>>w;
		add(u,v,w,0);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			ll a;
			cin>>a;
			add(n+i,j,a,i);
		}
	}
	sort(e+1,e+1+cnt);
	for(int i=0;i<(1<<k);i++)
	{
		ll sum=0;
		f2[0]=1;
		for(int j=1;j<=k;j++)
		{
			if((i>>(j-1))&1)
			{
				f2[j]=1;
				sum+=c[j];
			}
			else f2[j]=0;
		}
		ll plplpl=0;
		for(int i=1;i<=n+k;i++)
		{
			f[i]=i,f3[i]=0;
		}
		for(int j=1;j<=cnt;j++)
		{
			ll u=e[j].u;
			ll v=e[j].v;
			if(f2[e[j].op]==0) continue;
			if(fg(u)==fg(v)) continue;
			//cout<<u<<" "<<v<<" "<<e[j].w<<endl;
			f[fg(u)]=fg(v);
			sum+=e[j].w;
			if(!f3[u])
			{
				plplpl+=(u<=n);
			}
			if(!f3[v])
			{
				plplpl+=(v<=n);
			}
			f3[u]=f3[v]=1;
			if(plplpl>=n) break;
		}
		if(plplpl>=n) Min=min(Min,sum);
		//cout<<endl;
	}
	cout<<Min;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
