#include <bits/stdc++.h>

using namespace std;

bool b[5001];
long long ans;
int n;
int a[5001], c[5001];

inline void dfs(int i, int n, int s, int ma) {
	if (i == n + 1) {
		if (s > 2 * ma)
			ans++;
		return;
	}
	for (int j = 1; j <= n; i++)
		if (!b[j]) {
			b[j] = true;
			c[i] = a[j];
			dfs(i + 1, n, s + c[i], max(ma, c[i]));
			b[i] = false;
		}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 3; i <= n; i++) 
		dfs(1, i, 0, 0);
	printf("%lld\n", ans % 998244353);
	return 0;
}





