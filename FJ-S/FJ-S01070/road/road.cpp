#include<bits/stdc++.h>
using namespace std;
long long n,m,k,v[1000010],u[1000010],w[1000010],c[11],a[11][10010],f[10010][10010];
int main()
{
	freopen("road.in","r",stdin);freopen("toad.out","w",stdout);
	cin>>n>>m>>k;
	memset(f,1e9,sizeof(f));
	for(int i=1;i<=m;i++)
	{
		cin>>v[i]>>u[i]>>w[i];
		f[v[i]][u[i]]=min(f[v[i]][u[i]],w[i]);
		f[u[i]][v[i]]=min(f[v[i]][u[i]],w[i]);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
		if(c[j]==0){
			for(int j=1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					if(f[j][k]<=a[i][j]+a[i][k])	continue;
					else
					{
						f[j][k]=a[i][j]+a[i][k];
						f[k][j]=a[i][j]+a[i][k];
					}
				}
			}
		}
	}
	return 0;
}
