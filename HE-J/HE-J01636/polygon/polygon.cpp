#include<bits/stdc++.h>
#define ll long long
const int mod = 998244353;
using namespace std;
int n;
int a[5005];
ll c[5005];
ll ans;
ll qpow(ll x,ll p){
	ll ans1 = 1;
	while(p){
		if(p & 1)ans1 = (ll)(ans1 * x) % mod;
		x = (ll)(x * x) % mod;
		p = p >> 1;
	}
	return ans1;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort(a + 1,a + 1 + n);
	if(n < 3){
		puts("0");
		return 0;
	}
	if(n == 3){
		if(a[3] < (ll)(a[1] + a[2])){
			puts("1");
		}
		else puts("0");
		return 0;
	}
	c[1] = 1;
	for(int i = 2;i <= n;i ++){
		c[i] = 1ll * c[i - 1] * i;
		c[i] %= mod;
	}
	if(a[n] == 1){
		for(int i = 3;i < n;i ++){
			ll k;
			k = c[n];
			k = (ll)(k * qpow(c[i],mod - 2)) % mod;
			k = (ll)(k * qpow(c[n - i],mod - 2)) % mod;
			ans += k;
			ans %= mod;
		}
		ans = (ans + 1) % mod;
		cout << ans;
		return 0;
	}
	int ans1 = 0;
	for(int i = 1;i <= n;i ++){
		for(int j = i + 1;j < n;j ++){
			int l = j,r = n + 1;
			while(l + 1 != r){
				int mid = l + r >> 1;
				if(a[i] + a[j] <= a[mid])r = mid;
				else{
					l = mid;
				}
			}
			if(l == j)continue;
			ans = 0;
			int n1 = n - l;
			for(int h = 1;h < n1;h ++){
				ll k;
				k = c[n1];
				k = (ll)(k * qpow(c[h],mod - 2)) % mod;
				k = (ll)(k * qpow(c[n1 - h],mod - 2)) % mod;
				ans += k;
				ans %= mod;
			}
			ans = (ans + 1) % mod;
			ans1 = (ans1 + ans * (l - j) % mod);
			ans1 = (ans1 + (l - j) % mod);
		}
	}
	cout << ans1;
	int sum = 0;
	return 0;
}
