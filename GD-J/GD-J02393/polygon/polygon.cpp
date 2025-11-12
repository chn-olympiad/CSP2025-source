#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define i128 __int128
#define PII pair<int, int>
#define PLL pair<ll, ll>
using namespace std;

constexpr ll inf = (1ll << 62);
constexpr int N = 2e5 + 10, mod = 998244353;

vector<vector<ll>> c(5001, vector<ll> (5001));

void solve() {
	int n;
	ll ak = 0;
	cin >> n;
	vector<int> a(n);
	vector<vector<ll>> dp(n, vector<ll> (5001));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= i + 1; j++) {
//			cout << c[i + 1][j] << " ";
//			i128 x = (i128(dp[i][0]) + c[i + 1][j]);
//			if (x > (dp[i][0] + c[i + 1][j])) {
//				cout << "cinema\n";
//				return;
//			}
			dp[i][0] = (dp[i][0] + c[i + 1][j]) % mod;
		}
//		cout << "\n";
		for (int j = 1; j <= 5000; j++) {
//			i128 x = i128((!i ? 0 : dp[i - 1][j])) + (!i ? 0 : dp[i - 1][max(0, j - a[i])]);
//			if (x > (!i ? 0 : dp[i - 1][j]) + (!i ? 0 : dp[i - 1][max(0, j - a[i])])) {
//				cout << "cinema\n";
//				return;
//			}
			dp[i][j] = ((!i ? 0 : dp[i - 1][j]) + (!i ? 0 : dp[i - 1][max(0, j - a[i])])) % mod;
			if (a[i] > j) dp[i][j] = (dp[i][j] + 1) % mod;
		}
	}
//	for (auto i : a) cout << i << " ";cout << "\n";
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j <= a[n - 1]; j++) {
//			cout << dp[i][j] << " ";
//		}
//		cout << "\n";
//	}
	for (int i = 2; i < n; i++) {
//		i128 x = (ak + dp[i - 1][a[i]]);
//		if (x > (ak + dp[i - 1][a[i]])) {
//			cout << "cinema\n";
//			return;
//		}
		ak = (ak + dp[i - 1][a[i]]) % mod;
//		cout << ak << "\n";
	}
	cout << ak << "\n";
}
/*
考虑 dp，应该是第一维为考虑了前 i 个小木棍，且最大值为 j 的方案个数？ 
第二维是多余的，因为可以先将小木棍按长度从小到大排序
接着从前往后枚举，先考虑一维 dp，即考虑了前 i 个答案，则转移为：
f[i] = f[i - 1] + 必选 a[i] 的贡献
但这个贡献如何计算呢？一个感觉是因为已经排序了，所以有单调性，能否通过二分加组合数计算？
推一个式子得到，贡献为集合 S 的数量，S = {a1, a2, a3,..., ai} 其中，sum of S > 枚举到的数
所以应该是 dp 这个东西？dp[i][j] 表示考虑了前 i 个数且选出来的数 > j 的方案数
然后就有：

dp[i][j] = dp[i - 1][j] + dp[i - 1][max(0, j - a[i])] + [a[i] > j]

什么错误？为什么不对！！！！！！ 为什么我的 dp 数组中有的没有单调不升？反而数变大了？ 
哦，组合数的锅，搞个杨辉三角就行了……
不是，怎么第四个大样例又挂了！！！！！！ 啊，不会要开 ull 吧？可是这 n 还那么小，虽然大样例过了，但会不会炸掉啊？ 
嗯，刚刚生成了一下数据，似乎不会炸，不对啊，不应该炸 ll 啊，确实没炸，那为什么刚刚挂了呢？
I AK CSP-J 
*/

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	for (int i = 0; i <= 5000; i++) {
		c[i][0] = c[i][i] = 1;
	}
	for (int i = 1; i <= 5000; i++) {
		for (int j = 1; j <= i; j++) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
		}
	}
//	for (int i = 0; i <= 100; i++) {
//		for (int j = 0; j <= i; j++) {
//			cout << c[i][j] << " ";
//		}
//		cout << "\n";
//	}
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
