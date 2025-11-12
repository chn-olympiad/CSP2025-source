#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct IO {
	IO() { freopen("polygon.in", "r", stdin), freopen("polygon.out", "w", stdout); }
	~IO() { fclose(stdin), fclose(stdout); }
} io;
const int P = 998244353, V = 5000;
int n, a[5005], f[5005];
ll ans;
int main() {
	scanf("%d", &n);
	ans = 1;
	for (int i = 1; i <= n; i++) scanf("%d", a + i), ans = ans * 2 % P;
	ans = (ans + P - 1) % P;
	sort(a + 1, a + n + 1);
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= a[i]; j++) ans -= f[j];
		for (int j = V - a[i]; j >= 0; j--) {
			(f[j + a[i]] += f[j]) %= P;
		}
	}
	printf("%lld\n", (ans % P + P) % P);
	return 0;
}
// 8:49