#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define i128 __int128
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
bool be;
constexpr int N = 505, mod = 998244353;
int n, m, c[N], p[N], cnt[N];
char s[N];
int solve()
{
	int tot = 0, ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '0' || c[p[i]] <= tot) ++tot;
		else ++ans;
	}
	return ans;
}
bool en;
int main()
{
	freopen("employ.in", "r", stdin);
#ifdef xu
	cerr << (&be - &en) / 1024.0 / 1024 << " MB\n------------------" << endl;
#else
	freopen("employ.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> (s + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		p[i] = i;
	}
	do {
		++cnt[solve()];
	} while (next_permutation(p + 1, p + 1 + n));
	int ans = 0;
	for (int i = 0; i <= n; ++i) {
		cerr << cnt[i] << ' ';
		if (i >= m) {
			ans += cnt[i];
		}
	} cerr << '\n';
	cout << ans << endl;
	return 0;
}