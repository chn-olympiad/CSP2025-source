#include<bits/stdc++.h>
using namespace std;
int n,m,k,a,b,c,v,f[10005][10005],pd[10005][10005],nc[10020],sum,city;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b>>v;
		f[a][b]=v;
		f[b][a]=v;
		sum+=v*2;
	}
	int x=n;
	for(int i=1;i<=k;i++)
	{
		cin>>city;
		nc[++x]=city;
		//sum+=city;
		for(int j=1;j<=n;j++)
		{
			cin>>v;
			f[x][j]=v;
			f[j][x]=v;
			sum+=v*2;
		}
	}
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=x;j++)
		{
			if(f[i][j]==0&&i<=n&&j<=n||i>n&&j>n)
			{
				f[i][j]=-1;
			}
		}
	}
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=x;j++)
		{
			if(f[i][j]!=-1)
			{
				for(int k=1;k<=n;k++)
				{
					if(f[j][k]<f[i][j]&&f[j][k]!=-1&&f[i][k]!=-1&&pd[i][k]==0)
					{
						//cout<<f[i][j]<<" ";
						sum-=f[i][j];
						pd[i][j]=1;
						break;
					}
						
				}
			}
		}
	}
	sum/=2;
	for(int i=n+1;i<=x;i++)
	{
		int p=0;
		for(int j=1;j<=n;j++)
		{
			if(pd[i][j]!=1)
			{
				p=1;
				break;
			}
		}
		if(p=1)
		{
			sum+=nc[i];
		}	
	}
	cout<<sum;
	return 0;
}
