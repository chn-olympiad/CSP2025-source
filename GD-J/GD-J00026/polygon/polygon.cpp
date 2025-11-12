#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
long long n,a[5005],dp[5005],ans;
long long qpow(long long a,long long b)
{
	long long res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=0;i<=5000;i++) dp[i]=1;
	
	for(int i=1;i<=n;i++)
	{
		(ans+=qpow(2,i-1)+mod-dp[a[i]])%=mod;
		for(int j=5000-a[i];j>=0;j--){
			(dp[j+a[i]]+=dp[j])%=mod;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
