#include <stdio.h>
#include <algorithm>
#define int long long
using namespace std;
int n, a[5025];
int cnt;
const int mod = 998244353;
void f(int x, int c, int sum, int mx) {
	if (x >= 3) {
		if (sum > mx * 2) {
			cnt++;
			cnt %= mod;
		}
		if (x >= n) {
			return;
		}
	}
	for (int i = c; i < n; i++) {
		f(x + 1, i + 1, sum + a[i], max(mx, a[i]));
	}
}
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	f(0, 0, 0, 0);
	printf("%lld", cnt % mod);
	return 0;
}