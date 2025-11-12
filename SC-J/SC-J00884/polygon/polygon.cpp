#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5010;
const ll mod=998244353;
ll f[2][10010],a[N],ma=0,pw[N];
int n;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	pw[0]=1;
	for(int i=1;i<=n;i++) pw[i]=pw[i-1]*2ll%mod,ma=max(ma,2*a[i]);
	sort(a+1,a+1+n);
	f[0][0]=1;
	int v=0;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		v=v^1;
		ll sum=0;
		for(int j=0;j<=ma;j++)
		{
			f[v][j]=f[v^1][j];
			if(j>=a[i]) f[v][j]=(f[v][j]+f[v^1][j-a[i]])%mod;
			if(j<=a[i]) sum=(sum+f[v^1][j])%mod; 
		}
		ans=(ans+pw[i-1]-sum)%mod;
	}
	ans=(ans%mod+mod)%mod;
	printf("%lld",ans);
	return 0;
}