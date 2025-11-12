#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int n, a[N];
int ans;

void test(int k, int sum, int maxa, int tot) {
	if (k >= 4) {
		if (sum > maxa * 2) {
			ans++;
			ans %= 998244353;
		}
	}
	if (k > n) return;
	for (int i = tot;i <= n;i++) {
		test(k + 1, sum + a[i], max(maxa, a[i]), i + 1);
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) {
		scanf("%d", &a[i]);
	}
	test(1, 0, 0, 1);
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
