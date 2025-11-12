#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10;
int he[maxn], vis[maxn], a[maxn];
int n, k, ans = 0;
bool check(int x, int y) {
	for (int i = x; i <= y; i++) {
		if (vis[i]) return false;
	}
	return true;
}
void dfs(int is, int js, int num) {
	ans = max(ans, num);
	for (int i = is; i <= n; i++) {
		if (i == is) {
			for (int j = js; j <= n; j++) {
				if ((he[j]^he[i - 1]) == k && check(i, j)) {
					for (int l = i; l <= j; l++) {
						vis[l] = true;
					}
					dfs(i + 1, j + 1, num + 1);
				}
				for (int l = i; l <= j; l++) {
					vis[l] = false;
				}
			}
		} else {
			for (int j = i; j <= n; j++) {
				if ((he[j]^he[i - 1]) == k && check(i, j)) {
					for (int l = i; l <= j; l++) {
						vis[l] = true;
					}
					dfs(i + 1, j + 1, num + 1);
				}
				for (int l = i; l <= j; l++) {
					vis[l] = false;
				}
			}
		}
	}
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	bool flag = true, lag = true;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1 && a[i] != 0) lag = false;
		if (a[i] != 1) flag = false;
		he[i] = he[i - 1] ^ a[i];
	}
	if (lag) {
		if (k == 0) {
			int num = 0;
			if (flag) {
				cout << n / 2;
				return 0;
			} else {
				for (int i = 1; i <= n; i++) {
					if (a[i] == 1 && a[i + 1] == 1) num++, i++;
					if (a[i] == 0) num++;
				}
				cout << num;
				return 0;
			}
		}
		if (k == 1) {
			int num = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i] == 1) num++;
			}
			cout << num;
			return 0;
		}
	}
	dfs(1, 1, 0);
	cout << ans;
	return 0;
}