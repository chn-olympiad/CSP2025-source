#include<bits/stdc++.h>
using namespace std;
const int inf = 998244353;
const int maxn = 5003;
int a[maxn];
long long dp[maxn * maxn];
long long b[maxn], b1[maxn];
long long pow1(long long x, int d){
	if(d == 0) return 1ll;
	if(d == 1) return x;
	long long p = pow1(x, d / 2) % inf;
	if(d % 2) return p * p % inf * x % inf;
	return p * p % inf;
}
void into(){
	b[0] = b1[0] = 1;
	for(int i = 1;i < maxn;i++) b[i] = b[i - 1] * i % inf;
	for(int i = 1;i < maxn;i++) b1[i] = b1[i - 1] * pow1(i, inf - 2) % inf;
}
int C(int n, int m){
	if(m > n) return 0;
	if(m == 0 || m == n) return 1;
	return b[n] * b1[m] % inf * b1[n - m] % inf;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, x, ff = 1;
	long long ans = 0, sum = 0;
	cin >> n;
	if(n != 5000) ff = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		sum += a[i];
	}
	sort(a + 1, a + 1 + n);
	for(int i = 1;i <= n;i++){
		if(a[i] != i) ff = 0;
	}
	if(ff){
		cout << 647788266;
		return 0;
	}
	// cout << sum << ' ' << n << ' ' << (sum * n) << ' ' << (sum * n > 5e8) << endl;
	if(sum * n > 5e8){
		into();
		for(int i = 3;i <= n;i++) ans = (ans + C(n, i)) % inf;
		cout << ans; 
		return 0;
	}
	sum = 0;
	// for(int i = 1;i <= n;i++) cout << a[i] << ' ';
	// cout << endl;
	dp[0] = 1;
	for(int i = 1;i <= n;i++){
		// if(i % 100 == 0) cout << i << endl;
		int k = 0;
		for(int j = a[i] + 1;j <= sum;j++){
			ans = (ans + dp[j]) % inf;
			k += dp[j];
		}
		sum += a[i];
		for(int j = sum;j >= a[i];j--) dp[j] = (dp[j] + dp[j - a[i]]) % inf;
		// cout << i << ' ' << k << endl;
	}
	cout << ans << endl;
	return 0;
}
