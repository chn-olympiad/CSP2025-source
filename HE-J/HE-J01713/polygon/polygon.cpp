#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 3;
const int mod = 998244353;
int a[N], n;
bitset<N> bs;
set<int> st;
int dfs(int c) {
	if (c == n) {
		long long sum = 0;
		int maxn = 0;
		for (int i = 0; i < n; i++) if (bs[i]) {
			sum += a[i];
			maxn = max(maxn, a[i]);
		}
		if (sum > 2 * maxn) return 1;
		else return 0;
	}
	bs[c] = 1;
	int ans1 = dfs(c + 1) % mod;
	bs[c] = 0;
	int ans2 = dfs(c + 1) % mod;
	return ans1 + ans2;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	printf("%lld", dfs(0) % mod);
	return 0;
}
