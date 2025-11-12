//luogu uid:1025129 B road
#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct bdge
{
	int u,v;
	ll w;
}q[2000100];
ll fa[20010],d[20010],e[11][20010];
int find(int x)
{
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
void craft(int x,int y)
{
	fa[find(x)]=find(y);
}
bool cmp(bdge a,bdge b)
{
	return a.w<b.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	ll ans=0;
	bool A=1;
	cin>>n>>m>>k;
	int sm=m;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>q[i].u>>q[i].v>>q[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>d[i];
		if(d[i])A=0;
		for(int j=1;j<=n;j++)cin>>e[i][j];
	}
	if(A)
	{
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				m++;
				q[m].u=i+n;
				q[m].v=j;
				q[m].w=e[i][j];
			}
		}
		sort(q+1,q+m+1,cmp);
		for(int i=1;i<=m;i++)
		{
			int x=q[i].u,y=q[i].v;
			if(find(x)!=find(y))
			{
				ans+=q[i].w;
				craft(x,y);
			}
		}
	}
	else
	{
		ll oans=0;
		ans=2147483647;
		for(int g=0;g<pow(2,k);g++)
		{
			m=sm;
			for(int i=1;i<=k;i++)
			{
				if((g*1ll)&int(pow(2,i-1)*1ll))
				{
					for(int j=1;j<=n;j++)
					{
						m++;
						q[m].u=i+n;
						q[m].v=j;
						q[m].w=e[i][j];
					}
				}
			}
			sort(q+1,q+m+1,cmp);
			for(int i=1;i<=m;i++)
			{
				int x=q[i].u,y=q[i].v;
				if(find(x)!=find(y))
				{
					oans+=q[i].w;
					craft(x,y);
				}
			}
			ans=min(oans,ans);
		}
	}
	cout<<ans;
	return 0;
}
