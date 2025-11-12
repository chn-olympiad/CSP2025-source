#include <bits/stdc++.h>
using namespace std;

const int N = 1.1e6 + 10;
int a[N], dp[N], mx[N];
vector<int> v[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	int n, k;
	cin >> n >> k;
	v[0].push_back(0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] ^= a[i - 1];
		v[a[i]].push_back(i);
	}
	memset(dp, -0x3f, sizeof(dp));
	dp[0] = 0, mx[0] = 0;
	for (int i = 1; i <= n; i++) {
		int pre = (a[i] ^ k);
		dp[i] = 0;
		vector<int> &vec = v[pre];
		int maxj = lower_bound(vec.begin(), vec.end(), i) - vec.begin() - 1;
		if (maxj < 0) {
			mx[i] = mx[i - 1];
			continue;
		}
		dp[i] = max(dp[i], mx[vec[maxj]] + 1);
		mx[i] = max(mx[i - 1], dp[i]);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans << "\n";
	return 0;
}