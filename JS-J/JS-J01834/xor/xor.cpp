#include <bits/stdc++.h>
using namespace std;

int a[500005], pre[500005], vis[1 << 21];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	int lst = 0, ans = 0;
	vis[0] = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		pre[i] = pre[i - 1] ^ a[i];
		if (vis[pre[i] ^ m]) {
			for (int j = lst; j < i; j++) {
				vis[pre[j]] = 0;
			}
			lst = i;
			ans++;
		}
		vis[pre[i]] = 1;
	}
	printf("%d", ans);
	return 0;
}