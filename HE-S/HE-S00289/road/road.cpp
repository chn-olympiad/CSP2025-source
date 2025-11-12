#include<bits/stdc++.h>
using namespace std;
int lu,qw,n,m,k,u[11010][10111],v[1111111],w[111111],a,s,d,c[10001],a1[12][10001],a2[10001];
int vis=0,sd=98912;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>s>>d;
		u[a][s]=d;
		u[s][a]=d;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>qw>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a1[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		sd=111111111;
		for(int j=1;j<=n;j++)
		{
			if(u[i][j]!=0)
			{
				
				if(u[i][j]<sd)
				{
					sd=u[i][j];
					vis=vis+u[i][j]-sd;
				}
			}
		}
	}
	cout<<vis;
		fclose(stdin);
	fclose(stdout);
	return 0;
}
