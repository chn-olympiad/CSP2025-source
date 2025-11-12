#include<iostream>
#include<algorithm>
using namespace std;
long long sum,u[10005],v[10005],w1,n,m,k,c[10005],a[15][10005],f[10005][10005];
bool l[10005][10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>u[i]>>v[i]>>w1;
		if(!f[u[i]][v[i]])f[u[i]][v[i]]=w1;
		else if(f[u[i]][v[i]]>w1)f[u[i]][v[i]]=w1;
	}
		
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[k][i];	
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(!l[i][j])
			{
				long long m=min(f[u[i]][v[i]],f[v[i]][u[i]]);
				sum+=m;
				l[u[i]][v[i]]=1;
				l[v[i]][u[i]]=1;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}
