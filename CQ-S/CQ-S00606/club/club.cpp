#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;

constexpr int MAXN = 5e5, mod = 998244353, INF = 1e9; 

int T, n, cur, cnt[4], d[MAXN+5], p[MAXN+5], len;
LL ans;
vector<int> vec[4];
bool vis[MAXN+5];
struct node {
	int id, val;
	bool operator < (const node &T) const { return val > T.val; }
} a[MAXN+5][4];

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	IOS;
	cin >> T;
	while (T--) {
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= 3; ++j) cin >> a[i][j].val, a[i][j].id = j;
			sort(a[i] + 1, a[i] + 4);
			++cnt[a[i][1].id], ans += a[i][1].val;
			vec[a[i][1].id].emplace_back(i);
		}
		int pos = 0;
		for (int i = 1; i <= 3; ++i) if (cnt[pos] < cnt[i]) pos = i;
		len = 0;
		for (int i : vec[pos]) p[++len] = a[i][1].val - a[i][2].val;
		sort(p + 1, p + 1 + len);
		for (int i = 1; i <= cnt[pos] - n / 2; ++i) ans -= p[i];
		cout << ans << '\n';
		for (int i = 1; i <= 3; ++i) cnt[i] = 0, vector<int>().swap(vec[i]);
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
