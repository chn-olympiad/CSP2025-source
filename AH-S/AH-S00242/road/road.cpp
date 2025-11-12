#include<bits/stdc++.h>
using namespace std;
int n,m,k,sum;
int u[10024],v[10024],w[10024];
int c[11],a[11][10024];
int f[512][512][512],g[512][512];
pair<int,int>pir;
map<pair<int,int>,int>mp;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		pir.first=u[i];
		pir.second=v[i];
		mp[pir]=w[i];
		swap(pir.first,pir.second);
		mp[pir]=w[i];
		sum+=w[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
		for(int j=1;j<=n;j++)
		{
			for(int k=i+1;k<=n;k++)
			{
				pir.first=j;
				pir.second=k;
				if(mp[pir]>a[i][j]+a[i][k])
				{
					sum-=mp[pir];
					sum+=(a[i][j]+a[i][k]);
					mp[pir]=a[i][j]+a[i][k];
					swap(pir.first,pir.second);
					mp[pir]=a[i][j]+a[i][k];
				}
			}
		}
	}
	cout<<sum;
}
