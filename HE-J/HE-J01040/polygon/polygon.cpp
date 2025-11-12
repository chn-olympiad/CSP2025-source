#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353,N=5010;
int n,a[N];
ll po[N],inv[N],ans;
ll C(int n,int m)
{
	ll res=po[n]*(inv[m])%mod*(inv[n-m])%mod;
	return res;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	if(n==3)
	{
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1]) cout<<1;
		else cout<<0;
	}
	else
	{
		inv[1]=inv[0]=po[0]=1;
		for(int i=1;i<=n;++i) po[i]=po[i-1]*i%mod;
		for(int i=2;i<=n;++i) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
		for(int i=2;i<=n;++i) inv[i]=(inv[i]*inv[i-1])%mod;
		for(int i=3;i<n;++i)
			ans+=C(n,i);
		++ans;
		cout<<ans%mod;
	}
	return 0;
}
