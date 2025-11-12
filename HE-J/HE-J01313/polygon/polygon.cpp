#include <bits/stdc++.h>
#define int long long
const int mod=998244353;
int n,a[1000005],max=INT_MIN,num;
int32_t main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1; i<=n; i++)
		scanf("%lld",&a[i]);
	if(n<3)
		return printf("0"),0;
	if(n==3)
	{
		int len=0;
		for(int i=1; i<=n; i++)
		{
			max=std::max(max,a[i]);
			len+=a[i];
		}
		if(len>2*max)
			return printf("1"),0;
		else
			return printf("0"),0;
	}
	else
	{
		int len=0;
		for(int i=1;i<=n;i++)
			len+=a[i];
		printf("%lld",len%mod);
	}
	return 0;
}
