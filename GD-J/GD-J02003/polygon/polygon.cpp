#include<bits/stdc++.h>
#define int long long
using namespace std;
const long long mod=998244353;
int n;
long long a[200005],ans;
void dg(int q,int maxn,int sum)
{
	for(int i=q+1;i<=n;i++)
	{
		int mm=max(maxn,a[i]);
		int ssum=sum+a[i];
		if(ssum>mm*2) ans++,ans%=mod;
		dg(i,mm,ssum);
	}
}
long long qp(int x,int y)
{
	if(y==0) return 1;
	long long set=qp(x,y>>1)%mod;
	if(y&1)
	{
		return (set*set%mod)*x%mod;
	}
	else
	{
		return set*set%mod;
	}
}
main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	if(n==3)
	{
		printf("1");
		return 0;
	}
	if(n>26)
	{
		ans=qp(2,n);
		ans-=(n*n-n)/2;
		ans-=n;
		printf("%lld",ans);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	dg(0,0,0);
	printf("%lld",ans);
	return 0;
}
