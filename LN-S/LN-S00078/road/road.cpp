#include<bits/stdc++.h>
using namespace std;
long long n,m,k,sum,SUM;
const int N=10005;
long long a[N][N];
long long u[N],v[N],x[N],c[N];
int main()
{
	freopen("road.in",r,stdin);
	freopen("road.out",w,stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>x[i];	
	}
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=k;j++)
		{
			cin>>c[j]>>a[i][j];
		}
	}
	for(int i=1;i<=m;i++)
	{	
		sum=x[1];
		if(x[i]<sum)
		{
			x[i+1]=x[i];
			x[1]=sum;
		}	
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=k;j++)
		{
			SUM=c[1];
			if(c[j]<SUM)
			{
				SUM=c[j];
				c[1]=SUM;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=k;j++)
		{
			SUM=c[1];
			if(c[j]<SUM)
			{
				SUM=c[j];
				c[1]=SUM;
			}
		}
	}
	
	cout<<x[1]+c[1];
	return 0;
}
