#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int a[5005];
long long f[5005];
long long mi[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	mi[0]=1;
	for(int i=1;i<=n;i++) mi[i]=mi[i-1]*2%mod;
	long long ans=0;
	f[0]=1;
	for(long long i=1;i<=n;i++)
	{
		long long tot=mi[i-1];
		for(int j=0;j<=a[i];j++) tot=(tot+mod-f[j])%mod;
		ans=(ans+tot)%mod;
		for(int j=a[n];j>=a[i];j--) f[j]=(f[j]+f[j-a[i]])%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
