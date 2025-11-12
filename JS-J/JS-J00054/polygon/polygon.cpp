#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e3+5;
const ll mod=998244353;
ll n;
ll a[N];
ll sum[2*N];
ll ans;

ll query(ll x)
{
	ll ans=0;
	for(int i=0;i<=x;i++)
		ans+=sum[i],ans%=mod;
	return ans%mod;
}

ll quickpow(int x,int n)
{
	if(n==0)return 1;
	if(n==1)return x;
	ll res=quickpow(x,n/2);
	if(n%2)return (((res*res)%mod)*x)%mod;
	else return (res*res)%mod;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	sum[0]=1;
	for(ll i=1;i<=n;i++)
	{
		ans+=(quickpow(2,i-1)-query(a[i]))%mod,ans%=mod;
		//cerr<<ans<<endl;
		for(ll j=2*a[n];j>=a[i];j--)
			sum[j]+=sum[j-a[i]],sum[j]%=mod;
		//for(int j=0;j<=2*a[n];j++)
			//cout<<i<<" "<<j<<":"<<sum[j]<<endl;
	}
	cout<<(ans+mod)%mod<<endl;
	return 0;
}
