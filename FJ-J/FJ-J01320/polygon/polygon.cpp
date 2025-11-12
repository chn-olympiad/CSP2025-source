#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5005, mod = 998244353;

int n, a[N], vis[N], ans, fac[N], maxn;

int power(int a, int b){
	int ans = 1;
	while(b){
		if(b & 1) ans = (ans * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ans;
}

int inv(int x){
	return power(x, mod - 2);
}

int C(int n, int m){
	return (fac[n] * inv(fac[n - m]) % mod * inv(fac[m])) % mod;
}

void dfs(int k, int mx, int now, int v, int lst){
	if(now == k && v > (a[mx] * 2)){
		ans = (ans + 1) % 998244353;
		return ;
	}
	for(int i = lst + 1 ; i < mx ; i ++){
		if(!vis[i]){
			vis[i] = 1;
			dfs(k, mx, now + 1, v + a[i], i);
			vis[i] = 0;
		}
	}
}

signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	fac[0] = 1;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i];
		maxn = max(maxn, a[i]);
		fac[i] = (fac[i - 1] * i) % mod;
	}
	if(maxn == 1){
		for(int i = 3 ; i <= n ; i ++){
			ans = (ans + C(n, i)) % mod;
		}	
		cout << ans << '\n';
		return 0;
	}
	sort(a + 1, a + n + 1);
	for(int i = 3 ; i <= n ; i ++){
		for(int j = i ; j <= n ; j ++){
			vis[j] = 1;
			dfs(i, j, 1, a[j], 0);
			vis[j] = 0;
		}
	}
	cout << ans << '\n';
	return 0;
}
// 380 \o/\o/\o/\o/\o/\o/\o/\o/\o/\o/\o/\o/\o/\o/\o/\o/\o/\o/
// Luogu uid 749755
