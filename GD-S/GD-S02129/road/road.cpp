#include<bits/stdc++.h>
using namespace std;
long long n,m,k,xc[15][100005],sum;
struct f{
	long long a,b,w;
}x[1000005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	scanf("%lld%lld%lld",&x[i].a,&x[i].b,&x[i].w),sum+=x[i].w;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n+1;j++)
		scanf("%lld",&xc[i][j]);
	}
	cout<<sum;
	return 0;
} 
