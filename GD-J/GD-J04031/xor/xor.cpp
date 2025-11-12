#include<bits/stdc++.h>
using namespace std;
int n, k, a[3000010], lst[3000010], f[3000010], ans;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int now = 0;
	memset(lst, -1, sizeof(lst));
	f[0] = 0;
	lst[0] = 0;
	for (int i = 1; i <= n; i++) {
		now ^= a[i];
		if (lst[now ^ k] != -1) {
			f[i] = max(f[i - 1], f[lst[now ^ k]] + 1);
		}else f[i] = f[i - 1];
		lst[now] = i;
		ans = max(ans, f[i]);
	}
	cout << ans;
	return 0;
}
