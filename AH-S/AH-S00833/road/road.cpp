#include<iostream>
using namespace std;
const int N=1e6+5;
int n,m,k,u[N],v[N],c[15];
long long w[N],a[15][N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%lld",&u[i],&v[i],&w[i]);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	long long ans=0;
	for(int i=1;i<=m;i++)
		ans+=w[i];
	printf("%lld",ans);
	return 0;
}
