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

const int N = 5e5 + 5;
int a[N], dp[N], mx[1 << 20];
int main() {
	freopen("xor.in", "r", stdin); freopen("xor.out", "w", stdout);
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i] ^= a[i - 1];
	mems(mx, -0x3f), mx[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = max(dp[i - 1], mx[a[i] ^ k] + 1), mx[a[i]] = max(mx[a[i]], dp[i]);
	}
	cout << dp[n];
	return 0;
}
