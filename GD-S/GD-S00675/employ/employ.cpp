#include <bits/stdc++.h>

using namespace std;

#define lowbit(x) ((x) & -(x))
template<typename T> void chk_min(T &x, const T &y) { x = min(x, y); }
template<typename T> void chk_max(T &x, const T &y) { x = max(x, y); }
typedef pair<int, int> pii;
typedef long long ll;
const int N = 505, MOD = 998244353;

int n, m, mn = 1, ans = 0, c[N], p[N];
char s[N];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdin);
	cin >> n >> m >> s + 1;
	for (int i = 1; i <= n; ++i) chk_min(mn, s[i] - '0'), p[i] = i;
	for (int i = 1; i <= n; ++i) cin >> c[i];
	do {
		int suc = 0, fal = 0;
		for (int i = 1; i <= n; ++i) {
			int x = c[p[i]];
			if (fal >= x || s[i] == '0') ++fal;
			else ++suc;
		}
		ans += suc >= m;
	} while (next_permutation(p + 1, p + n + 1));
	cout << ans % MOD;
	return 0;
} 
