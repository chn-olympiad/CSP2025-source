#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int a[N];
bool vis[N];
int n, k;
long long ans;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	bool flag = false;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] != 1) flag = true;
	}
	if (!flag) {
		if (k == 0) {
			for (int i = 2; i <= n; i += 2) ans += n - i + 1;
		} else {
			for (int i = 1; i <= n; i += 2) ans += n - i + 1; 
		}
	} else {
		for (int len = 1; len <= n; len++) {
			for (int i = 1; i + len - 1 <= n; i++) {
				int x = i, y = i + len - 1;
				long long nowans = a[x];
				for (int kk = x + 1; kk <= y; kk++) nowans ^= a[kk];
				if (nowans == k) {
					bool fflag = false;
					for (int j = x; j <= y; j++) {
						if (vis[j]) {
							fflag = true;
							break;
						}
					}
					if (!fflag) {
						ans++;
						for (int j = x; j <= y; j++) {
							vis[j] = true;
						}
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
} 
