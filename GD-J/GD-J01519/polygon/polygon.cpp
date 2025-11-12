#include<cstdio>
#include<algorithm>
using namespace std;
const long long mod=998244353;
long long a[5005];
long long f[5005][5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,W=0;
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		W=max(W,a[i]);
	}
	W++;
	sort(a+1,a+n+1);
	f[0][0]=1;
	for(long long i=0;i<n;i++)
	{
		for(long long j=0;j<=W;j++)
		{
			long long k=j+a[i+1];
			if(k>W)
			{
				k=W;
			}
			f[i+1][k]=(f[i+1][k]+f[i][j])%mod;
			f[i+1][j]=(f[i+1][j]+f[i][j])%mod;
		}
	}
	long long ans=0;
	for(long long i=1;i<=n;i++)
	{
		for(long long j=a[i]+1;j<=W;j++)
		{
			ans=(ans+f[i-1][j])%mod;
		}
	}
	printf("%lld",ans%mod);
	return 0;
}
