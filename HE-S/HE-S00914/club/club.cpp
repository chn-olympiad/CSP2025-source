#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5, MAXCLUB = 3 + 5;
int a[MAXN][MAXCLUB], num[MAXCLUB], n, ans, tmp1[MAXN];

void dfs(int p, int sum) {
	if (p > n) {
		ans = max(ans, sum);
		return;
	}
	for (int i = 1; i <= 3; i++) {
		if ((n / 2) <= num[i]) {
			continue;
		}
		num[i]++;
		dfs(p + 1, sum + a[p][i]);
		num[i]--;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	srand(time(0));
	int t;
	cin >> t;
	while (t--) { // 5 Omax(2e6) MAXN = 1e5
		bool flaga = true, flagb = true;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
				if (a[i][3] != 0) {
					flaga = false;
					flagb = false;
				}
				if (a[i][2] != 0) {
					flaga = false;
				}
			}
		}
		if (flaga) {
			for (int i = 1; i <= n; i++) {
				tmp1[i] = a[i][1];
			}
			sort(tmp1 + 1, tmp1 + 1 + n, greater<int>());
			int tmp11 = 0;
			for (int i = 1; i <= n / 2; i++) {
				tmp11 += tmp1[i];
			}
			cout << tmp11 << endl;
		}
		else if (n <= 10) {
			ans = 0;
			dfs(1, 0);
			cout << ans << endl;
		}
		else {
			int tmp234 = 0;
			for (int i = 1; i <= n; i++) {
				tmp234 += max({a[i][1], a[i][2], a[i][3]});
			}
			cout << tmp234 << endl;
		}
	}
	return 0;
}
