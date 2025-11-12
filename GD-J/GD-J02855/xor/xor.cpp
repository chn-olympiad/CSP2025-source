#include <cstdio>
#include <iostream>
using namespace std;
int n, k, ans;
int h[500005];
int f[500005];
int a[500005];
void dfs(int, int);
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin >> n >> k;
	bool flag = false;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > 1) {
			flag = true;
		}
	}
	if (flag || k > 1) {
		dfs(n, 1);
		cout << ans;
	} else {
		int t = 0, s = 0;;
		for (int i = 1; i <= n; i++) {
			if (a[i]) {
				t++;
			} else {
				s++;
			}
		}
		if (k == 1) {
			cout << t;
		} else {
			cout << t / 2 + s;
		}
	}
	return 0;
}
void dfs(int x, int step) {
	if (x == 0) {
		int i = 1, tmpans = 0;
		for (int i = 1; i < step; i++) {
			int start = f[i - 1] + 1, end = f[i - 1] + h[i];
			int tmp = 0;
			for (int j = start; j <= end; j++) {
				tmp ^= a[j];
			}
			if (tmp == k) {
				tmpans++;
			}
		}
		ans = max(ans, tmpans);
	} else {
		for (int i = 1; i <= x; i++) {
			f[step] = f[step - 1] + i;
			h[step] = i;
			dfs(x - i, step + 1);
		}
	}
}
// 40 pts
