#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int a[N];
int n, k;
long long ans;

void test(long long nn, int tot, int sum) {
	if (tot > n) {
		ans = max(ans, nn);
		return;
	}
	for (int i = tot;i <= n;i++) {
		sum = sum == -1?a[i]:sum ^ a[i];
		if (sum == k) {
			test(nn + 1, i + 1, -1);
		}
	}
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1;i <= n;i++) {
		scanf("%d", &a[i]);
	}
	test(0, 1, -1);
	printf("%lld", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
