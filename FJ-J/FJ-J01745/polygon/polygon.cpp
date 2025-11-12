#include <bits/stdc++.h>
#define ll long long
#define N 5003
#define M 998244353

int n;
int a[N];

ll qpow(ll a,ll b){
	a %= M;
	ll ans = 1;
	while(b){
		if(b & 1){
			ans = (ans * a) % M;
		}
		a = (a * a) % M;
		b >>= 1;
	}
	return ans;
}

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> n;
	int mxx = 0;
	ll ans = 0;
	for(int i = 1;i <= n;i++){
		std::cin >> a[i];
		mxx = std::max(mxx,a[i]);
	}
	if(mxx == 1){
		ans = qpow(2,n) - n - (n * (n - 1) / 2) - 1;
		ans %= M;
		ans = (ans + M) % M;
		std::cout << ans;
		return 0;
	}
	std::sort(a + 1,a + n + 1);
	for(int i = 1;i < (1 << n);i++){
		int sum = 0;
		int mx = 0;
		for(int j = 0;j < n;j++){
			if(i & (1 << j)){
				sum += a[j + 1];
				mx = std::max(mx,a[j + 1]);
			}
		}
		if(sum > 2 * mx){
			ans = (ans + 1) % M;
		}
	}
	std::cout << ans;
	return 0;
}

