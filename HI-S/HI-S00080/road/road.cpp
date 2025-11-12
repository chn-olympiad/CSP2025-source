#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m,n,k;
	cin>>n>>m>>k;
	long long u[n+5],v[m+5],w[1000000000];
	long long c[n+1];
	long long a[1000000000][100];
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=k;j++)
		{
			cin>>c[j];
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(a[i][j]>=a[i+1][j])
			{
				a[i][j]=a[i+1][j];
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=k;j++)
		{
			for(int i=1;i<=n;i++)
			{
				cnt+=a[i][j];
			}			
		}
	}
	cout<<cnt;	
	return 0;
}

