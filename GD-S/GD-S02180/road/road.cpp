#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000100],v[1000100],w[1000100],a[11][10050],c[10010][10010],s,x[11];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		c[v[i]][u[i]]=c[u[i]][v[i]]=w[i];
	}
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				s+=c[i][j];
			}
		}
		cout<<s;
		return 0;
	} 
	int mi=INT_MAX,e;
	for(int i=1;i<=k;i++)
	{	
		cin>>x[i];
		if(mi>x[i])
		{
			mi=x[i];
			e=i;
		}
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	s+=x[e];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
				if(c[i][j]==0)
				{
					c[i][j]=a[e][j]+a[e][i];
				}	
				else
				{
					c[i][j]=min(c[i][j],a[e][j]+a[e][i]);
				}
				
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			s+=c[i][j];
		}
	}
	cout<<s;
	return 0;
}
