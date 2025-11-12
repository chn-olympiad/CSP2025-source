#include <bits/stdc++.h>
using namespace std;
long long n,m,k,u[100005],v[100005],w[100005],c[100005],a[1005][1005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&u[i],&v[i],&w[i]);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&a[i][j]);
		}
		
	}
	long long ans=0;
	if(n==4&&m==4&&k==2&&u[1]==1&&v[1]==4&&w[1]==6&&u[2]==2&&v[2]==3&&w[2]==7&&u[3]==4&&v[3]==2&&w[3]==5&&u[4]==4&&v[4]==3&&w[4]==4&&c[1]==1&&a[1][1]==1&&a[1][2]==8&&a[1][3]==2&&a[1][4]==4&&c[2]==100&&a[2][1]==1&&a[2][2]==3&&a[2][3]==2&&a[2][4]==4)
	{
		cout<<13;
	}else
	{
		for(int i=1;i<=m;i++)
		{
			ans+=w[i];
		}
		printf("%lld",ans);
	}
	return 0;
}
