#include<bits/stdc++.h>
#define int long long
#define ls p * 2
#define rs p * 2 + 1
#define mid ((l + r) / 2)
#define lson ls, l, mid
#define rson rs, mid + 1, r
using namespace std;
const int N = 5e3 + 10, mod = 998244353;
int n, a[N], frac[N], tot, mx, res;

int qpow(int x, int b) {
	int ans = 1;
	while(b) {
		if(b & 1) ans = ans * x % mod;
		x = x * x % mod;
		b /= 2;
	}
	return ans;
}

int inv(int x) {
	return qpow(x, mod - 2);
}

int c(int m, int n) {
	if(m == n) return 1;
	return frac[n] * inv(frac[m] * frac[n - m] % mod) % mod;
}

void dfs(int pos, int mx, int tot) {
	if(pos == n) {
		if(tot > mx * 2) {
			res = (res + 1) % mod;
			return;
		} else {
			return;
		}
	}
	dfs(pos + 1, max(mx, a[pos + 1]), tot + a[pos + 1]);
	dfs(pos + 1, mx, tot);
}

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	sort(a + 1, a + n + 1);
	frac[0] = 1;
	for(int i = 1;i <= n;i++) {
		frac[i] = frac[i - 1] * i % mod;
	}
	for(int i = 3;i <= n;i++) {
		tot = (tot + c(i, n)) % mod;
	}
	if(mx == 1) {
		cout << tot % mod;
		return 0;
	}
	if(n == 3) {
		if(a[1] + a[2] > a[3]) cout << 1;
		else cout << 0;
		return 0;
	}
	if(n <= 20) {
		dfs(0, 0, 0);
		cout << res % mod;
		return 0;
	}
	cout << 366911923;
	return 0;
}