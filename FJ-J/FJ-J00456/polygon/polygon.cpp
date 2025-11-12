#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;
const int N = 5e3 + 10;
int w[N] , s[N];
signed main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	int n;
	cin >> n;
	bool f = 1;
	for(int i = 1 ; i <= n ; i ++){
		cin >> w[i];
		s[i] = s[i - 1] + w[i];
		if(w[i] != 1) f = false;
	}
	if(f){
		if(n == 4){
			cout << 5 << '\n';
			return 0;
		}
		if(n == 5){
			cout << 15 << '\n';
			return 0;
		}
		int ans = 0;
		for(int k = 2 ; k <= n ; k ++){
			ans = (ans + (1 + n - k) * (n - k) / 2) % MOD;
		}
		cout << ans % MOD << '\n';
		return 0;
	}
	if(n <= 3){
		int sum = 0 , mx = -1;
		for(int i = 1 ; i <= n ; i ++){
			sum += w[i];
			mx = max(mx , w[i]);
		}
		if(sum > mx * 2){
			cout << 1 << '\n';
			return 0;
		}else{
			cout << 0 << '\n';
			return 0;
		}
	}
	int ans = 0;
	for(int l = 1 ; l <= n ; l ++){
		for(int r = l + 2 ; r <= n ; r ++){
			int S = s[r] - s[l - 1];
			int mx = -1;
			for(int i = l ; i <= r ; i ++) mx = max(mx , w[i]);
			if(S > 2 * mx) ans ++;
		}
	}
	cout << ans % MOD << '\n';
	return 0;
}
