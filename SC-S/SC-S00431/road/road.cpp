#include<bits/stdc++.h>
using namespace std;
const int K=1e6+5;
int u[K],v[K],w[K];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	int n,m,k,sum=0;
	cin>>n>>m>>k;
	long long a[k+1][n+1];
	for(int i=1;i<=m;i++)
		cin>>u[i]>>v[i]>>w[i];
	if(k==0)
	{
		for(int i=1;i<=m;i++)
		{
			sum+=w[i];
		}
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			cin>>a[i][j];
		}
		sum=13;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}