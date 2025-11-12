#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[1000005][5],c[15][10005],b[10005],s=0,f[15],js=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=3;j++)
			cin>>a[i][j];
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n+1;j++)
			cin>>c[i][j];
	for(int i=1;i<m;i++)
		for(int j=1;j<m;j++)
			if(a[j][1]>a[j+1][1])
			{
				swap(a[j],a[j+1]);
			}
	b[++s]=1;
	while(s<n)
	{
		long long lt;
		for(int i=1;i<=n;i++)
		{
			bool be=true;
			for(int j=1;j<=s;j++)
				if(b[j]==i)
				{
					be=false;
					break;
				}
			if(be)
			{
				lt=i;
				break;
			}
		}
		long long kx=INT_MAX;
		for(int i=1;i<=m;i++)
		{
			if(a[i][1]==lt||a[i][2]==lt)
			{
				for(int j=1;j<=s;j++)
				{
					if(j==a[i][1]||a[i][2]==j)
					{
						kx=i;
						break;
					}
				}
				if(kx!=INT_MAX)
					break;
			}
		}
		long long csh=INT_MAX,ci,lti,sf;
		for(int i=1;i<=k;i++)
		{
			long long js=0,minn=INT_MAX;
			for(int j=2;j<=n+1;j++)
				minn=min(minn,c[i][j]);
			if(c[i][n+2]==0)
			{
				minn+=c[i][1];
				if(csh>minn)
				{
					csh=minn;
					c[i][n+2]=1;
					sf=true;
					lti=i;
				}
			}
			else
			{
				csh=minn;
				lti=i;
				sf=false;
			}
		}
		b[++s]=lt;
		if(csh<=kx)
		{
			if(sf==true)
			{
				c[lti][n+2]=1;
			}
			js+=csh;
		}
		else
			js+=kx;
	}
	cout<<js;
	return 0;
}
