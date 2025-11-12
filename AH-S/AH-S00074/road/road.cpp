#include<bits/stdc++.h>
using namespace std;
int u[1000001],v[1000001],w[1000001],c[11],a[11][10001];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	long long sum=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	if(k==0)
	{
		sort(w+1,w+m+1);
		for(int i=1;i<=n-1;i++)
			sum+=w[i];
		cout<<sum;
	}else
	{
		
	}
	return 0;
}
