#include <cstdio>
#include <algorithm>
#define int long long

const int N = 5e3 + 10, Mod = 998244353;
int a[N];

int qpow(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = (ans * a) % Mod;
		a = a * a % Mod, b >>= 1;
	}
	return ans;
} 

signed main() {

    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    int n;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
    std :: sort(a + 1, a + n + 1);
    if (n < 3) printf("0\n");
    else if (n == 3) {
        if (a[1] + a[2] + a[3] > a[3] * 2) printf("1\n");
        else printf("0\n");
    }
    else printf("%lld\n", (qpow(2, n - 2) - 1 + Mod) % Mod);

    return 0;
}