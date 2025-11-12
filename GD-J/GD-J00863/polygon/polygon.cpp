#include <bits/stdc++.h> 
using namespace std;
#define int long long
const int mod=998244353;
int n,a[5005],t[5005],ans;
int qpow(int a,int b) {
	if(b<0) return 0;
	int ans=1;
	for(;b;b/=2,a=(a*a)%mod) if(b%2) ans=(ans*a)%mod;
	return ans;
}
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	sort(a+1,a+n+1),t[0]=1;
	for(int i = 1;i <= n;i ++) {
		ans=(ans+qpow(2,i-1))%mod;
		for(int j = 5000;j >= a[i];j --) t[j]+=t[j-a[i]];
		for(int j = 1;j <= a[i];j ++) ans=((ans-t[j])%mod+mod)%mod;
	}
	cout << ans;
	return 0;
}
