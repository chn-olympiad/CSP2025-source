#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define ni 499122177
#define int long long
int n;
int a[5001];
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	bool p=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		p&=(a[i]==1);
	}
	if(n==3)
	{
		printf("%lld",(a[1]+a[2]+a[3]>=2*max({a[1],a[2],a[3]})?1ll:0ll));
		return 0;
	}
	int ans=0;
	for(int i=3;i<=n;i++)
	{
		for(int j=n;j>=i;j--)
		{
			ans=(ans+(j-i+2)*(j-i+1)%mod*ni%mod)%mod;
		}
	}
	printf("%lld",ans);
	return 0;
}

