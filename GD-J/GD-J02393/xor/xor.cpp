#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define i128 __int128
#define PII pair<int, int>
#define PLL pair<ll, ll>
using namespace std;

constexpr ll inf = (1ll << 62);
constexpr int N = 2e6 + 10;

vector<int> lst(N, -1);

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n), s(n), f(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s[i] = (!i ? 0 : s[i - 1]) ^ a[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int x = (s[i] ^ k);
		if (lst[x] != -1) {
			f[i] = f[lst[x]] + 1;
		} else if (!x) {
			f[i] = 1;
		}
		if (i) {
			f[i] = max(f[i], f[i - 1]);
		}
		lst[s[i]] = i;
		ans = max(ans, f[i]);
	}
	cout << ans << "\n";
}
/*
3 3
3 3 3
贪心？ 
注意到 xor 满足前缀和的运算，所以可以先求一遍异或前缀和，接下来考虑枚举右端点 
然后贪心的考虑，一个区间如果越长，那么包含的可能的答案区间就越多
所以对于每一个右端点，只需要找最近的一个满足条件的位置即可，可以拿一个桶维护
*/

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
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
