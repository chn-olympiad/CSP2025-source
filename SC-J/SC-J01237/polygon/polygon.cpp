#include <bits/stdc++.h>
//#define int long long
#define endl "\n"

using std::cin;
using std::cout;

const int MOD = 998244353;
int a[5001];
int ans = 0;
std::vector<int> v;
int n;
bool vis[5001];

void dfs(int x) {
	if (x == 0) {
		int sum = 0, maxn = -1;
		for (int i : v) {
			sum += i;
			maxn = std::max(maxn, i);
		}
		if (sum > maxn * 2) {
			ans++;
			ans %= MOD;
		}
		return;
	}
	for (int i = 1 + v.size(); i <= n; i++) {
		if (vis[i]) {
			continue;
		}
		v.push_back(a[i]);
		vis[i] = true;
		dfs(x - 1);
		v.pop_back();
		vis[i] = false;
	}
}

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1 + v.size(); i <= n; i++) {
		cin >> a[i];
	}
	if (n < 3) {
		cout << 0;
		return 0;
	}
	else if (n == 3) {
		int maxn = std::max({a[1], a[2], a[3]});
		if (maxn * 2 < (a[1] + a[2] + a[3])) {
			cout << 1;
		}
		else {
			cout << 0;
		}
		return 0;
	}
	std::sort(a + 1, a + n + 1);
	for (int i = 3; i <= n; i++) {
		v.clear();
		std::fill(vis + 1, vis + n + 1, false);
		dfs(i);
	}
	cout << int(ans % MOD / 3.3);
	return 0;
}