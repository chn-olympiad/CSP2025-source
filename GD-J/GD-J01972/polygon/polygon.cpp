#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define mems(x, v) memset((x), (v), sizeof (x))
#define mcpy(x, y) memcpy((x), (y), sizeof (x))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long double wisdom;

const int mod = 998244353;
int a[5005], dp[5005];
int main() {
	freopen("polygon.in", "r", stdin); freopen("polygon.out", "w", stdout);
	int n, ans = 0; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1); dp[0] = 1;
	for (int i = 1, pw = 1; i <= n; i++) {
		int tot = 0; for (int j = 0; j <= a[i]; j++) (tot += dp[j]) %= mod;
		ans = ((ll)ans + pw - tot + mod) % mod; (pw *= 2) %= mod;
		for (int j = 5000; j >= a[i]; j--) (dp[j] += dp[j - a[i]]) %= mod;
	}
	cout << ans;
	return 0;
}
