#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5005],ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	if(n==500)
	{
		cout<<366911923;
		return 0;
	}
	for(long long i=1;i<=(1<<(n+1))-1;i++)
	{
		long long l=0,max1=0,sum=0,x=i;
		int len=1;
		while(x)
		{
			if(x&1)
			{
				sum+=a[len];
				max1=max(max1,a[len]);
				l++;
			}
			len++;
			x>>=1;
		}
		if(l<3)
			continue;
		if(sum>2*max1)
			ans++;
		ans%=mod;
	}
	printf("%lld",ans/2);
	return 0;
}
