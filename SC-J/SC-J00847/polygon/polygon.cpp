#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,a[5005];
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	long long S=(1<<n)-1,num=0;
	for(long long i=1;i<=S;i++)
	{
		long long ma=-1,sum=0;
		for(long long j=0;j<n;j++)
		{
			if((i>>j)&1)
			{
				ma=max(a[n-j],ma);
				sum+=a[n-j];
			}
		}
		if(sum>2*ma)num++;
		num%=MOD;
	}
	cout<<num;
	return 0;
}