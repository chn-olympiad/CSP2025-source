#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int n, m, c[N], p[N], ans;
char s[N];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> s + 1;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}
	if (m == n) {
		bool flag = 1;
		for (int i = 1; i <= n; ++i) {
			if (s[i] != '1') {
				flag = 0;
				break;
			}
		}
		cout << flag;
		return 0;
	}
	iota(p + 1, p + n + 1, 1);
	do {
		int cnt = 0, res = 0;
		for (int i = 1; i <= n; ++i) {
			if (s[i] == '0' || c[p[i]] <= cnt) {
				++cnt;
			} else {
				++res;
			}
		}
		ans += res >= m;
	} while (next_permutation(p + 1, p + n + 1));
	cout << ans << '\n';
	return 0;
}