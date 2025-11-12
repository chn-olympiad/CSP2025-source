#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, a[5005], sign[5005], max_a;
long long c = 1, ans;
void dfs(int cnt, int sum, int max_a, int p) {
	if(cnt == n + 1)	return;
	for(int i = p; i <= n; i++) {
		if(sign[i] == 0) {
			if(cnt >= 3) {
				if(sum + a[i] > 2 * max(max_a, a[i])) {
//					cout << sum + a[i] << ' ' << max(max_a, a[i]) << endl;
					ans++;
					ans %= mod;
				}
			}
			sign[i] = 1;
			dfs(cnt + 1, sum + a[i], max(max_a, a[i]), i + 1);
			sign[i] = 0;
		}
	}
}
void f(int x) {
	for(int i = 1; i <= x; i++) {
		c = c * (x + 1 - i) / i;
//		cout << c << endl;
		if(i >= 3)	ans += c;
		ans %= mod;
	}
	cout << ans;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		max_a = max(max_a, a[i]);
	}
	if(max_a == 1) {
		f(n);
		return 0;
	}
	dfs(1, 0, 0, 1);
	cout << ans;
	return 0;
}
