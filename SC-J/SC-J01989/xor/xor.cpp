#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct IO {
	IO() { freopen("xor.in", "r", stdin), freopen("xor.out", "w", stdout); }
	~IO() { fclose(stdin), fclose(stdout); }
} io;
int n, k, a[500005], b[2000005], ans;
int main() {
	scanf("%d%d", &n, &k);
	b[0] = 1;
	for (int i = 1, j = 0; i <= n; i++) {
		scanf("%d", a + i), a[i] ^= a[i - 1];
		if (b[a[i] ^ k]) {
			ans++;
			while (j < i) b[a[j++]]--;
		}
		b[a[i]]++;
	}
	printf("%d\n", ans);
	return 0;
}