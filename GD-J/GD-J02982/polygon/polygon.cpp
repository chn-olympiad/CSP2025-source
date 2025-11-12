#include <bits/stdc++.h>

using namespace std;

const int N = 5555, MOD = 998244353;
long long ans;
bool AllOne = true;
int a[N], n, m;
int C(int a, int b) {
	int ans = 1;
	for(int i = a; i > a - b; i--) {
		ans *= i;
		ans %= MOD;
	}
	for(int i = b; i >= 2; i--) ans /= i;
	return ans;
}
void SpecialPoint() {
	int ans = 0;
	for(int m = 3; m <= n; m++) {
		ans += C(n, m);
	}
	cout << ans;
	
}
void dfs(int cn, int sum, int maxx, int np) {
	if(cn >= m) {
		if(sum > maxx * 2) {
			ans++;
		}
		return;
	}
	for(int i = np + 1; i <= n - m + cn + 1; i++) {
		dfs(cn + 1, sum + a[i], max(maxx, a[i]), i);
	}
}
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] != 1) AllOne = false;
	}
	if(AllOne) {
		SpecialPoint();
		return 0;
	}
	for(int i = 3; i <= n; i++) {
		m = i;
		dfs(0, 0, 0, 0);
		ans %= MOD;
	}
	cout << ans;
	
	return 0;
}
