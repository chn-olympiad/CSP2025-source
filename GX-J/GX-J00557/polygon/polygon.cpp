#include<bits/stdc++.h>
#define ll long long
#define N 5010
#define MOD 998244353
using namespace std;

ll n;
ll a[N],s[N],sum;
int dp[N*N],p[N*N],t[N];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1; i<=n; i++)
	{
		scanf("%lld",a+i);
		t[a[i]]++;
	}
	sort(a+1,a+n+1);
	for(ll i=1; i<=n; i++)
		s[i]=s[i-1]+a[i];
	p[a[1]+a[2]]=1;
	for(ll i=3; i<=n; i++)
	{
		for(ll j=2*a[i]+1; j<=s[i]; j++)
		{
			dp[j]+=p[j-a[i]]%MOD;
			dp[j]%=MOD;
		}
		/*for(ll j=a[i]*2+1; j<=s[i]; j++)
			dp[j]=(dp[j]+p[j-a[i]])%MOD;*/
		for(ll j=s[i]; j>=a[i]+1; j--)
		{
			p[j]+=p[j-a[i]]+t[j-a[i]];
			if(j-a[i]==a[i])
				p[j]--;
			p[j]%=MOD;
		}
	}
	for(ll i=0; i<=s[n]; i++)
		sum+=dp[i],sum%=MOD;
	printf("%lld",sum);
    return 0;
}

