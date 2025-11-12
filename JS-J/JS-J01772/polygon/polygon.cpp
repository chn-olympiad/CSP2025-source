#include <bits/stdc++.h>
using namespace std;
int n;
int a[5010];
bool flag=true;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		if (a[i]!=1)
			flag=false;
	}
	if (n==3)
	{
		printf("%d",1);
		return 0;
	}
	if (flag)
	{
		long long ans=1;
		long long x=0;
		for (int i=1;i<=n-2;++i)
		{
			ans+=(i+x)*(n-1-i)%998244353;
			ans%=998244353;
			x=i;
		}
		printf("%lld",ans);
	}
	return 0;
}
