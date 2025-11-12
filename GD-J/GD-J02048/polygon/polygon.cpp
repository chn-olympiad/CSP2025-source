#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

typedef long long ll;
const int N = 5003,mod = 998244353;
int n;
ll a[N],qz[N],ans,f[N],inv[N];

ll qpow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=(a*a)%mod;b=b>>1;
	}
	return res;
}

int main(){
	cin >> n;
	for(int i=1;i<=n;++i)
		scanf("%lld",&a[i]),qz[i]=qz[i-1]+a[i];
	f[1] = 1;
	for(int i=2;i<=n;++i) f[i]=(f[i-1]*i)%mod;
	inv[n] = qpow(f[n],mod-2);
	for(int i=n-1;i>=0;--i) inv[i]=inv[i+1]%mod*(i+1)%mod;
	sort(a+1,a+n+1);
	for(int len=3;len<=n;++len){
		for(int l=1;l+len-1<=n;++l){
			int r = l+len-1;
			int n=r-l-1,m=len-2;
			if(qz[r-1]-qz[l]>a[r]){
				ans = ans+f[n]*inv[m]%mod*inv[n-m]%mod;
			}
		}
	}cout << ans;
	return 0;
}
