#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define i128 __int128
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
bool be;
constexpr int N = 1e5 + 5;
int n, mid[N], cnt[20005];
struct node {
	int b[3];
}a[N];
bool en;
int main()
{
	freopen("club.in", "r", stdin);
#ifdef xu
	cerr << (&be - &en) / 1024.0 / 1024 << " MB\n------------------" << endl;
#else
	freopen("club.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		int c[3] = {0, 0, 0}, ans = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i].b[0] >> a[i].b[1] >> a[i].b[2];
			mid[i] = max_element(a[i].b, a[i].b + 3) - a[i].b;
			++c[mid[i]];
			ans += a[i].b[mid[i]];
		}
		int id = max_element(c, c + 3) - c;
		if (c[id] > n / 2) {
			memset(cnt, 0, sizeof cnt);
			for (int i = 1; i <= n; ++i) {
				if (mid[i] == id) {
					int mx = 0;
					for (int j : {0, 1, 2}) {
						if (j != id) {
							mx = max(mx, a[i].b[j]);
						}
					}
					++cnt[a[i].b[mid[i]] - mx];
				}
			}
			int tot = c[id] - n / 2;
			for (int i = 0; i <= 20000; ++i) {
				while (tot > 0 && cnt[i] > 0) {
					ans -= i;
					--tot, --cnt[i];
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}