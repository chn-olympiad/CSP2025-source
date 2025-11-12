#include <bits/stdc++.h> //zhi neng pian dao 80 fen or less qwq
#define int long long
using namespace std;

const int mod = 998244353;

int a[5005], ans, n;
bool cmp(int a, int b) {
	return a > b;
}

int qpow(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

//inline int C(int n, int m) {
//	return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
//}
//inline init() {
//	fac[0] = 1;
//	for (int i = 1; i <= 5002; i++) fac[i] = fac[i - 1] * i % mod;
//	ifac[5002] = qpow(5002, mod - 2);
//	for (int i = 5001; i >= 0; i--) ifac[i] = ifac[i + 1] * (i + 1) % mod;
//}

int sum[5005];

void dfs(int now, int maxx, int sumx) {
	if (sumx + sum[now] <= maxx * 2) return ;
	if (sumx > maxx * 2) {
		if (now > n) {ans ++; return ;}
		(ans += qpow(2, n - now + 1)) %= mod;
		return ;
	}
	dfs(now + 1, maxx, sumx);
	dfs(now + 1, max(maxx, a[now]), sumx + a[now]);
}

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	

	cin >> n;
	int maxx = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; maxx = max(maxx, a[i]);
	}
	
	if (maxx == 1) {
		for (int i = 3; i <= n; i++) 
			(ans = (ans << 1) % mod + (i - 1) * (i - 2) / 2 % mod) %= mod;
		cout << ans << "\n";
		exit(0);
	}
	
	sort(a + 1, a + 1 + n, cmp);
	for (int i = n; i >= 1; i--) sum[i] = sum[i + 1] + a[i];
	dfs(1, 0, 0);
	cout << ans;
	return 0;
}

/*
3 : 1
4 : 5
5 : 16
6 : 43
7 : 99
8 : 219
zhi jie guan cha, rong yi fa xian,
gui lv:
quan 1 =  2 * last + [1 + (i-2)]*(i-2) / 2

f*** ... pian ni de
*/

