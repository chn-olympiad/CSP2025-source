#include<bits/stdc++.h>
#define ll long long
#define N 5010
using namespace std;
int n,ans;
int mod=998244353;
int a[N],f[N];
int pw(ll a,int b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	f[0]=1;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		int sum=0;
		for(int j=0;j<=a[i];j++)
			sum=(sum+f[j])%mod;
		int tmp=((pw(2,i-1)-sum)%mod+mod)%mod;
		ans=(ans+tmp)%mod;
		for(int j=5000;j>=a[i];j--)
			f[j]=(f[j]+f[j-a[i]])%mod;
	}
	cout<<ans;
	return 0;
}
