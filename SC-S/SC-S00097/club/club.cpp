#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdint>
#include <cstring>
using namespace std;
typedef pair <int, int> pii;
typedef int64_t i64;
const int N = 1e5 + 10;
const int M = 210; // 检查大小、空间

int n;
i64 dp[M][M][M], val[N][4];

void solvedp() {
	for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) for(int k = 0; k <= n; k++) dp[i][j][k] = 0;
	for(int i = 0; i < n; i++) {
		for(int u = 0; u <= min(i, n / 2); u++) {
			for(int v = 0; v <= min(i, n / 2); v++) {
				int w = i - u - v;
				if(w < 0 || w > min(i, n / 2)) continue;
				if(u + 1 <= n / 2) dp[i + 1][u + 1][v] = max(dp[i + 1][u + 1][v], dp[i][u][v] + val[i + 1][1]);
				if(v + 1 <= n / 2) dp[i + 1][u][v + 1] = max(dp[i + 1][u][v + 1], dp[i][u][v] + val[i + 1][2]);
				if(w + 1 <= n / 2) dp[i + 1][u][v] = max(dp[i + 1][u][v], dp[i][u][v] + val[i + 1][3]);
			}
		}
	}
	i64 ans = 0;
	for(int u = 0; u <= n / 2; u++) {
		for(int v = 0; v <= n / 2; v++) {
			int w = n - u - v;
			if(w < 0 || w > n / 2) continue;
			ans = max(ans, dp[n][u][v]);
		}
	}
	cout << ans << '\n';
	return void(0);
}

vector <i64> v;
void solvet() {
	for(int i = 1; i <= n; i++) v.push_back(val[i][1]);
	sort(v.begin(), v.end(), greater <int> ());
	i64 ans = 0;
	for(int i = 0; i < n / 2; i++) ans += v[i];
	cout << ans << '\n';
	return void(0);
}

void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> val[i][1] >> val[i][2] >> val[i][3];
	}
	if(n <= 200) 
		solvedp();
	else 
		solvet();
	return void(0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout); // 测试 freopen
	int T; cin >> T;
	while(T--) solve();
	return 0;
}
// 检查调试语句、i64、空间、时间、代码版本、freopen
// Think twice, code once.
// 注意 Win 和 Linux 双过
// rp++　!!!!!
// 16:07 club O(n^3)