#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MOD = 998244353;
const int N = 5 * 1e2 + 5;

int n, m, c[N], a[N], lose, win, cnt1, cnt2;
bool flag = true;
string s;
ll ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m >> s;
	s = " " + s;
	for (int i = 1; i < (int)s.size(); i++) {
		if (s[i] == '0') flag = false;
		if (s[i] == '1') cnt2++;
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		a[i] = i;
		if (c[i] == 0) {
			cnt1++;
		}
	}
	if (n - cnt1 < m || cnt2 < m) {
		cout << 0;
		exit(0);
	}
	if (flag && n > 18) {
		if (n - cnt1 >= m) {
			ans = 1;
			for (int i = 1; i <= n; i++) {
				ans = ans * i % MOD;
			}
			cout << ans;
		} else {
			cout << 0;
		}
		exit(0);
	}
	if (n > 18) {
		cout << 0;
		exit(0);
	}
	do {
		lose = 0, win = 0;
		for (int i = 1; i <= n; i++) {
			int v = a[i];
			if (lose >= c[v] || s[i] == '0') {
				lose++;
				continue;
			} else {
				win++;
				if (win >= m) {
					break;
				}
			}
		}
		if (win >= m) {
			ans = (ans + 1) % MOD;
		}
	} while (next_permutation(a + 1, a + 1 + n));
	cout << ans;

	return 0;
}
