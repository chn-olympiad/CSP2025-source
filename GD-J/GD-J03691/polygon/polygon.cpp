#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+10,mod=998244353;
int n,m,a[N],mx;
ll b[N],ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),mx=max(mx,a[i]);
	sort(a+1,a+n+1);
	b[0]=1;
	ll sum=1;
	for(int i=1;i<=n;i++)
	{
		int sum2=0;
		for(int j=0;j<=a[i];j++) sum2=(sum2+b[j])%mod;
		ans=(ans+sum-sum2+mod)%mod;
		sum=(sum*2)%mod;
		for(int j=mx-a[i];j>=0;j--) b[j+a[i]]=(b[j+a[i]]+b[j])%mod;
	}
	printf("%lld",ans);
	return 0;
}
