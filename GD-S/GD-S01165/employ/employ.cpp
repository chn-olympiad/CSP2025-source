#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define Pii pair<int, int>
#define fst first
#define snd second
#define pb push_back
#define endl '\n'

int p[15];
int c[510];

constexpr LL MOD = 998244353;

signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	bool flag = true;
	for (auto i: s) {
		if (i == '0') {
			flag = false;
			break;
		}
	}
	if (flag) {
		LL ans = 1, nn = n;
		for (int i = 1; i <= n; ++i) {
			if (c[i] == 0) {
				--nn;
			}
		}
		for (int i = 1; i <= nn; ++i) {
			ans *= i;
			ans %= MOD;
		}
		cout << ans << endl;
		return 0;
	}
	s = " " + s;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}
	if (n <= 10) {
		for (int i = 1; i <= n; ++i) {
			p[i] = i;
		}
		LL ans = 0;
		do {
			LL cnt = 0, res = 0;
			for (int i = 1; i <= n; ++i) {
				if (cnt < c[p[i]] && s[i] == '1') {
					++res;
				} else {
					++cnt;
				}
			}
//			for (int i = 1; i <= n; ++i) {
//				cout << p[i] << " \n"[i == n];
//			}
//			cout << res << endl;
			if (res >= m) {
				++ans;
				if (ans > MOD) {
					ans -= MOD;
				}
			}
		} while (next_permutation(p + 1, p + 1 + n));
		cout << ans << endl;
		return 0;
	}
	return 0;
}

