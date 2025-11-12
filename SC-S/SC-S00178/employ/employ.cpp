#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) p << 1
#define rs(p) p << 1 | 1

const int N = 1e5 + 5;
const int P = 1e9 + 7;
const int INF = 1e18;

int n, m, a[N], c[N];
int p[N], ans = 0;
string s;

void solve1 () {
	for (int i = 1; i <= n; i++) a[i] = s[i - 1] - '0';
	for (int i = 1; i <= n; i++) cin >> c[i], p[i] = i;
	do {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 0 || cnt >= c[p[i]]) cnt++;
		}
		ans = (ans + (n - cnt >= m)) % P;
	} while (next_permutation(p + 1, p + n + 1));
	cout << ans;
}

void solve2 () {
	cout << 0;
}

void solve () {
	cin >> n >> m >> s;
	if (n <= 18) solve1();
	else solve2 ();
}

signed main () {
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T = 1; // cin >> T;
	while (T--) solve ();
	return 0;
}