#include<bits/stdc++.h>
using namespace std;
int u[10005],v[10005];
long long w[100005],c[100005];
int a[15][10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,k;
	long long m;
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++)
		cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
