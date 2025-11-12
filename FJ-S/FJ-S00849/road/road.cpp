#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=1000001+11*10001;
struct Edge
{
	ll u,v,d;
}e[M];
bool cmp(Edge x,Edge y)
{
	return x.d<y.d;
}
int fa[M];
int find(int x)
{
	if(fa[x]!=x)
	{
		fa[x]=find(fa[x]);
	}
	return fa[x];
}
int c[11];
bool exi(int st,int i)
{
	return (st>>i)&1;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,es=0;
	cin>>n>>m>>k;
	bool check=1;
	for(int i=1;i<=m;i++)
	{
		int u,v,d;
		cin>>u>>v>>d;
		e[++es]={u,v,d};
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]!=0)
		{
			check=0;
		}
		for(int j=1;j<=n;j++)
		{
			int d;
			cin>>d;
			if(d!=0)
			{
				check=0;
			}
			e[++es]={n+i,j,d};
		}
	}
	if(check)
	{
		cout<<0;
		return 0;
	}
	sort(e+1,e+es+1,cmp);
	ll ans=LLONG_MAX;
	for(int st=0;st<(1<<k);st++)
	{
		ll res=0,poi=n;
		for(int i=1;i<=k;i++)
		{
			if(exi(st,i-1))
			{
				res+=c[i];
				poi++;
			}
		}
		if(res>ans)
		{
			continue;
		}
		for(int i=1;i<=n+k;i++)
		{
			fa[i]=i;
		}
		int sum=0;
		for(int i=1;i<=es;i++)
		{
			int u=e[i].u,v=e[i].v;
			if(u>n&&!exi(st,u-n-1))
			{
				continue;
			}
			int fu=find(u),fv=find(v);
			if(fu!=fv)
			{
				fa[fu]=fv;
				res+=e[i].d;
				if(res>ans)
				{
					break;
				}
				sum++;
			}
			if(sum==poi-1)
			{
				break;
			}
		}
		ans=min(ans,res);
//		if(st==0)
//		{
//			cout<<ans<<'\n';
//		}
	}
	cout<<ans;
}
