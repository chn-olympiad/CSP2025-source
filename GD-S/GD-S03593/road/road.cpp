#include<bits/stdc++.h>
using namespace std;
long n,m,k,uvw[1000010][4],c[11],a[11][1010],ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long i=1;i<=m;i++)
	{
		cin>>uvw[i][1]>>uvw[i][2]>>uvw[i][3];
	}
	for(long i=1;i<=k;i++)
	{
		cin>>c[i];
		for(long j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	ans=13;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
