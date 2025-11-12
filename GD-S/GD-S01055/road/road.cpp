#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u[1000005],v[1000005],w[1000005],c[15],a[10005];
long long ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1; i<=m; i++)
	{
		scanf("%lld%lld%lld",&u[i],&v[i],&w[i]);
		ans+=w[i];
	}
	for(int i=1; i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(int j=1; j<=n; j++)
		{
			scanf("%lld",&a[i]);
		}
	}
	printf("%lld\n",ans);
	return 0;
 } 
