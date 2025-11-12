#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
int n,a[5005],cnt[5005];
map <int,ll> f;
ll ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[i]=cnt[i-1]+a[i];
	f[0]=1;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(n>2&&cnt[i-1]>a[i]) ans=(ans+f[cnt[i-1]-a[i]-1])%mod;
		for(int j=cnt[i];j>=a[i];j--)
			f[j]=(f[j]+f[j-a[i]])%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
