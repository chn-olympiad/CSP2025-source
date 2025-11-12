#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 5;
int pre[N];
void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		cin >> pre[i];
		pre[i] ^= pre[i - 1];
		// cout << pre[i] << ' ';
	}
	if (k == 0) {
		cout << n / 2;
		return 0;
	}
	// [l, r]µÄÈ¨Öµ = pre[r] ^ pre[l - 1] 
	int ans = 0, l = 1;
	for (int r = 1; r <= n; r ++) {
		// cout << l << ' ' << r << '\n';
		if ((pre[r] ^ pre[l - 1]) == k) {
			ans ++;
			l = r + 1;
		}
		if (l == 1 && pre[r] == k) {
			ans ++;
			l = r + 1;
		}
		while ((pre[r] ^ pre[l - 1]) > k) {
			l ++;
		}
	}
	cout << ans << '\n';
	return ;
}
int main(void) {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(0);
	cout.tie(nullptr) -> sync_with_stdio(0);
	solve();
	return 0;
} 
