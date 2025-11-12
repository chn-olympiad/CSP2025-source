// “ÏªÚ∫Õ(xor) 
#include <cstdio>
#define LL long long
using namespace std;
const int N = 500005;
LL n, k, num, ans, a[N];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf ("%lld%lld", &n, &k);
	for (int i = 1; i <= n; i++) scanf ("%lld", &a[i]);
	num = a[1];
	for (int i = 2; i <= n; i++) {
		if (num == k) {
			ans++;
			num = a[i];
			continue;
		}
		num ^= a[i];
	}
	if (num == k) ans++;
	printf ("%lld", ans);
	return 0;
}
