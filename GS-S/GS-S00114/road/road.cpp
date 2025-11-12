#include<bits/stdc++.h>
using namespace std;
int x[10004][10004],a[10004],cc[5004008],c;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u,v,w,ii=0,sum=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		x[u][v]=w;
		x[v][u]=w;
	}
	for(int i=1;i<=n;i++)
	{
		x[i][i]=99999999;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(j!=k)
				{
					if(x[j][k]==0)
					{
						x[j][k]=a[j]+a[k]+c;
					}
					else
					{
						x[j][k]=min(a[j]+c+a[k],x[j][k]);
					}
				}
			}
		}
	}
	for(int i=1;i<=n-1;i++)
	{
		for(int j=n;j>i;j--)
		{
			cc[ii]=x[i][j];
			ii++;
		}
	}
	bool bb;
	for(int i=ii-1;i>0;i--)
	{
		bb=0;
		for(int j=0;j<i;j++)
		{
			if(cc[j]>cc[j+1])
			{
				swap(cc[j],cc[j+1]);
				bb=1;
			}
		}
		if(bb==0)
		{
			break;
		}
	}
	for(int i=0;i<n-1;i++)
	{
		sum+=cc[i];
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
