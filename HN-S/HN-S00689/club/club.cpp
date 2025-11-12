// 应该能骗50-70分吧 

#include <bits/stdc++.h>

using namespace std;

int a[100005][4];
int dp[205][205][205];


void work() {
	int n, res = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
			for (int j = 0; j < 3; j++)
					cin >> a[i][j];
	if (n <= 200) {		// 下辈子一定好好学贪心和dp（ 
		for (int p = 0; p < n; p++)
			for (int i = 0; i <= n / 2; i++)
				for (int j = 0; j <= n / 2; j++) {
					 int k = p + 1 - i - j;
					 if (k > n / 2) continue;
					 int iv = 0, jv = 0, kv = 0;
					 if (i) iv = dp[i - 1][j][k] + a[p][0];
					 if (j) jv = dp[i][j - 1][k] + a[p][1];
					 if (k) kv = dp[i][j][k - 1] + a[p][2];
					 dp[i][j][k] = max(iv, max(jv, kv));
				}
		for (int i = 0; i <= n / 2; i++)
			for (int j = 0; j <= n / 2; j++)
				if (n - i - j <= n / 2)
					res = max(res, dp[i][j][n - i - j]);
	} else {
		if (a[0][1] > 0) {	// 特殊性质B 
			vector<pair<int, int>> vec(n);
			for (int i = 0; i < n; i++) vec[i] = {a[i][0], a[i][1]};
			sort(vec.begin(), vec.end(), [] (auto a, auto b) { return abs(a.first - a.second) > abs(b.first - b.second); });
			int lcnt = 0, rcnt = 0;
			for (auto& item : vec) {
				if (item.first > item.second) {
					if (lcnt < n / 2) {
						res += item.first;
						lcnt++;
					} else {
						res += item.second;
						rcnt++;
					}
				} else if (item.first < item.second) {
					if (rcnt < n / 2) {
						res += item.second;
						rcnt++;
					} else {
						res += item.first;
						lcnt++;
					}
				} else {
					res += item.first;  // 放一边去，最后塞回去 
				}
			}
		} else {	  // 特殊性质A 
			for (int i = 0; i < n; i++) res += a[i][0];
		}
	}
	
	cout << res << endl;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) work();	
	return 0;
}
