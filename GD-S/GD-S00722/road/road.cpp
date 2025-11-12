#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[10001][10001],w[11][10002],k1[11],flog[11];
ll n,m,k;
bool f[10001];
ll bfs(ll num,ll nm)
{
	ll mix=10000000,x=0,y=0;
	for(ll j=1;j<=n;j++)
	{
		for(ll i=1;i<=n;i++)
		{
			if(f[j]&&!f[i])
			{
				if(mix>a[j][i]&&a[j][i]!=0)
					mix=a[j][i],y=i;
				
			}
		}
	}
	for(ll j=1;j<=n;j++)
	{
		for(ll i=1;i<=n;i++)
		{
			if(f[j]&&!f[i])
			{
				for(ll t=1;t<=k;t++)
				{
					if(w[t][i]+w[t][j]<mix&&i!=j)
					{
						if(flog[t]>=0)
							mix=w[t][i]+w[t][j],y=i;
						else
						{
							flog[t]+=(mix-w[t][i]+w[t][j]);
						}
					}
				}
			}
		}
	}
	f[y]=1;
	nm++;
	if(nm==n-1)
	{return num+mix;
	}
	return bfs(num+mix,nm);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++)
	{
		int a1,b,c;
		cin>>a1>>b>>c;
		a[a1][b]=c;
		a[b][a1]=c;
	}
	for(ll t=1;t<=k;t++)
	{
	cin>>w[t][0];
	flog[t]=-w[t][0];
	for(ll i=1;i<=n;i++)
	{
		
		cin>>w[t][i];
	}
	}
	
	f[1]=1;
	ll ans=bfs(0,0),maxx=0;
	for(int t=1;t<=k;t++)
	{
		if(flog[t]>=0)
		{for(int i=1;i<=n;i++)
			{
			f[i]=0;
			}
			f[1]=1;
			ans=bfs(0,0)+w[t][0];
		}
			
	}
	cout<<ans;//·Ö¸øÄãÁË 
	return 0;
}
