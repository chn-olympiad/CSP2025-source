#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll a[5005];
const ll Mod=998244353;
ll f[5005];
ll c[5005][5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	for(int i=1;i<=5000;i++)
	{
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%Mod;
	}
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	ll mx=a[1]+a[2];
	ll ans=0;
	f[mx]++;
	for(int i=3;i<=n;i++)
	{
		ll ls=0;	
		for(int j=2;j<i;j++) ls=(ls+c[i-1][j])%Mod;
		ll ls1=0;
		for(int j=0;j<=a[i];j++) ls1+=f[j],ls1%=Mod;
		ans+=(ls-(ls1)+Mod)%Mod,ans%=Mod;
		for(int j=5000-a[i];j>=0;j--)
		{
			f[j+a[i]]+=f[j];
			f[j+a[i]]%=Mod;
		}
		for(int j=1;j<i;j++) if(a[j]+a[i]<=5000) f[a[j]+a[i]]++,f[a[j]+a[i]]%=Mod;
	}
	printf("%lld",ans);
}
