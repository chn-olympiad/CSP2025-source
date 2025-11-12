#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 5, Mod = 998244353;
int n, a[maxn];
long long ans;
bool chos[maxn];

bool check() {
	int sum = 0, mx = -1;
	for (int i = 1; i <= n; i++) {
		if (chos[i]) {
			sum += a[i];
			mx = max(mx, a[i]);
		}
	}
	if (sum > 2 * mx) return true;
	return false;
}

void dfs(int now) {
	if (now > n) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (chos[i]) cnt++;
		}
		if (cnt < 3) return ;
		if (check()) {
			ans++;
			ans %= Mod;
		}
		return ;
	}
	chos[now] = true;
	dfs(now + 1);
	chos[now] = false;
	dfs(now + 1);	
}

void solve1() {
	dfs(1);
	cout << ans << endl;
}
//
//void solve2() {
//	int x = 1, y = 1;
//	for (int i = 1; i <= n; i++) {
//		x *= i;
//		x %= Mod;
//	}
//	for (int i = 1; i <= n - 3; i++) {
//		y *= i;
//		y %= Mod;
//	}
//	ans = x / ((6 * y) % Mod) % Mod;
//	cout << ans % Mod << endl;
//}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	int mxa = -1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mxa = max(mxa, a[i]);
	}
	if (n <= 20) solve1();
//	if (mxa == 1) solve2();
}
