#include <bits/stdc++.h>

using namespace std;

int xornum[500005], n, k, num[500005], vis[500005], ans; 

int xorsum(int l, int r) {
	return (xornum[r] xor xornum[l-1]);
}

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 0; i <= n; i++) {
		vis[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		if (i == 1) {
			xornum[i] = num[i];
		} else {
			xornum[i] = num[i] xor xornum[i - 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j + i <= n; j++) {
			if (xorsum(i, i + j) == k) {
				int flag = 1;
				for (int l = i; l <= i + j; l++) {
					if (vis[l] == 1) {
						flag = 0;
					}
				}
				if (flag) {
					for (int l = i; l <= i + j; l++) {
						vis[l] = 1;
					}
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}