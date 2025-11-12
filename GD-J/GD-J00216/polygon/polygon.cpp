# include <cstdio>
# include <algorithm>
# define int long long
# define mod 998244353
using namespace std;
int n,a[50007],g[50007],f[50007],sum;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	for(int j=1;j<n;j++)
		if(a[j]>a[j+1]) swap(a[j],a[j+1]);
	g[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=2*a[n]+1;j++)
		{
			int p=j+a[i];
			if(p>2*a[n]+1) p=2*a[n]+1;
			f[p]=(f[p]+g[j])%mod;
		}
		for(int j=2*a[i]+1;j<=2*a[n]+1;j++) sum=(sum+f[j])%mod;
		for(int j=0;j<=2*a[n]+1;j++) g[j]=(g[j]+f[j])%mod,f[j]=0;
	}
	printf("%lld",sum);
	return 0;
}
