#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int a[N], p[N];
int vis[1 << 20];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		p[i] = p[i - 1] ^ a[i];
	}
	int ans = 0;
	vis[0] = 1;
	if (k) {
		for (int i = 1; i <= n; i++) {
			vis[p[i]] = 1;
			if (vis[p[i] ^ k]) {
				ans++;
				memset(vis, 0, sizeof vis);
				vis[p[i]] = 1;
			}
		}
	} else {
		for (int i = 1; i <= n; i++) {
			if (vis[p[i] ^ k]) {
				ans++;
				memset(vis, 0, sizeof vis);
				vis[p[i]] = 1;
			}
			vis[p[i]] = 1;
		}
	}
	cout << ans;
	return 0;
}
