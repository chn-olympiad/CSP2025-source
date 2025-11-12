#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
const int N = 5e3+5;
int n, a[N], f[N], cnt[N];
signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+1+n);
	int ans = 1;
	for(int i = 1; i <= n; i++) (ans *= 2) %= mod;
	ans -= n*(n-1)/2+n+1;
	ans = (ans%mod+mod)%mod;
	f[0] = 1;
	for(int i = 1; i <= n; i++){
		for(int x = 2; x <= a[i]; x++){
			ans -= f[x]-cnt[x];
		}
		ans = (ans%mod+mod)%mod;
		cnt[a[i]]++;
		for(int j = a[n]; j >= a[i]; j--){
			f[j] += f[j-a[i]];
			if(f[j] >= mod) f[j] -= mod;
		}
	} cout << ans;
	return 0;
}
