// 2^20 = 1048576
#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++ i)
#define per(i, l, r) for (int i = (l); i >= (r); -- i)
using namespace std;
const int N = 5e5 + 10, M = (1<<20) + 10;
int n, k, a[N], q[N], dp[N];
vector <int> pos[M];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> k;
	rep(i, 1, n) {
		cin >> a[i];
		q[i] = q[i - 1] ^ a[i];
		pos[q[i]].push_back(i);
	}
	per(i, n, 1) {
		dp[i] = dp[i + 1];
		int q_r = q[i - 1] ^ k;
		auto it = lower_bound(pos[q_r].begin(), pos[q_r].end(), i);
		if (it != pos[q_r].end()) {
			int r = *it;
			dp[i] = max(dp[i], dp[r + 1] + 1);
		}
	}
	cout << dp[1];
	return 0;
}
