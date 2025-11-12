#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M = 5000 + 10, N = 5e5 + 10;
const ll mod = 998244353;
ll n, a[M], f[2][N], sum, ans, maxn;

void work1() {
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j <= sum; j ++) {
			f[1][j] = f[0][j];
			if (j >= a[i]) 
				f[1][j] = (f[1][j] + f[0][j - a[i]]) % mod;
		}
		ll p = 2 * a[i] + 1;
		for (int j = p; j <= sum; j ++) 
			ans = (ans + f[0][j - a[i]]) % mod;
		for (int j = 0; j <= sum; j ++) 	
			f[0][j] = f[1][j], f[1][j] = 0;
	}	
} 

void work2() {
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j <= 2 * maxn; j ++) {
			f[1][j] = f[0][j];
			if (j >= a[i]) 
				f[1][j] = (f[1][j] + f[0][j - a[i]]) % mod;
		}
		f[1][2 * maxn + 1] = f[0][2 * maxn + 1] * 2 % mod;
		for (int j = 2 * maxn - a[i] + 1; j <= 2 * maxn; j ++) 
			f[1][2 * maxn + 1] = (f[1][2 * maxn + 1]  + f[0][j]) % mod;
		for (int j = a[i] + 1; j <= 2 * maxn; j ++) 
			ans = (ans + f[0][j]) % mod;
		ans = (ans + f[0][2 * maxn + 1]) % mod;
		for (int j = 0; j <= 2 * maxn + 1; j ++) 
			f[0][j] = f[1][j], f[1][j] = 0;
//		for (int j = 1; j <= 2 * maxn + 1; j ++) 
//			cout << f[0][j] << " ";
//		cout << "\n";
//		cout << "ans = " << ans << "\n";
	}
}

int main(){
	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; i ++) 
		cin >> a[i], sum += a[i];
	sort(a + 1, a + 1 + n); maxn = a[n];
	f[0][0] = 1;
	if (n <= 500) work1();
	else work2();
	cout << ans % mod << "\n";
	
	return 0;
}

/*
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j <= sum; j ++) {
			f[1][j] = f[0][j];
			if (j >= a[i]) 
				f[1][j] = (f[1][j] + f[0][j - a[i]]) % mod;
		}
		ll p = 2 * a[i] + 1;
		for (int j = p; j <= sum; j ++) 
			ans = (ans + f[0][j - a[i]]) % mod;
		for (int j = 0; j <= sum; j ++) 	
			f[0][j] = f[1][j], f[1][j] = 0;
	}
*/
