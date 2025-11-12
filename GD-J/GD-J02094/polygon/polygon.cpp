#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353

int n,a[114514];
int qz[114514];
int j_y_h[5005][5005];

bool cmp(int x,int y) {
	return x > y;
}

int qp(int x,int y) {
	int res = 1,a = x;
	while (y) {
		if (y % 2 == 1) {
			res *= a;
			res %= mod;
		}
		y /= 2;
		a *= a;
		a %= mod;
	}
	return res % mod;
}

int dfs(int st,int k) {
	if (qz[st] < k) {
		return 0;
	}
	if (st < 1) {
		return (k < 0);
	}
	if (k < 0) {
		return j_y_h[st][k]= qp(2,st) % mod;
	}
	if (j_y_h[st][k] != 0) return j_y_h[st][k] % mod;
	int res = 0;
	res += dfs(st - 1,k - a[st]) % mod;
	res += dfs(st - 1,k) % mod;
	res %= mod;
	return j_y_h[st][k] = res % mod;
} 

signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for (int i = 1; i <= n; i++) {
		qz[i] = qz[i - 1] + a[i];
		qz[i] %= mod;
	}
	int ans = 0;
	for (int i = n; i >= 1; i--) {
		int _x_z_ = upper_bound(a + 1,a + n + 1,a[i]) - a - 2;
		_x_z_ = min(_x_z_,i - 1);
		ans += dfs(_x_z_,a[i]) % mod;
		ans %= mod;
	}
	cout << ans;
	return 0;
}
