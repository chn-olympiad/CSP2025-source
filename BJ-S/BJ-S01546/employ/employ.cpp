#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N = 505, mod = 998244353;
ll fac[N];
bool s[N];
int c[N];
void upd(int &x, int y) {
	unsigned t = x + y;
	x = min(t, t - mod);
}
int p[N];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		s[i] = (c == '1');
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		p[i] = i;
	}
	int res = 0;
	do {
		int now = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i])
				now += (i - 1 - now < c[p[i]]);
		}
		res += (now >= m);
	} while (next_permutation(p + 1, p + n + 1));
	cout << res << '\n';
	return 0;
}
