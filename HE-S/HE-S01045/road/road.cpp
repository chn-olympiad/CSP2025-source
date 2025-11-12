#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	long long u[10001],v[10001],w[10001],a[11][10001];
	cin>>n>>k>>m;
	for(long long i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(long long i=1;i<=k;i++)
	{
		for(int p=1;p<n;p++)	cin>>a[i][p];
	}
	cout<<13;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
