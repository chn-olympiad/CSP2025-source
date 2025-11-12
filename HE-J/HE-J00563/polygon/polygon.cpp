#include <bits/stdc++.h>

using namespace std;

const int N = 5010, mod = 998244353;
int n, a[N], cnt[N];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}
	sort(a + 1, a + n + 1);
	long long ans = 0;
	for (int i = 1; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = j + 1; k <= n; k++)
				if (a[i] + a[j] > a[k] && a[k] - a[j] < a[i])
					ans += a[k], ans %= mod;
	printf("%lld\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
