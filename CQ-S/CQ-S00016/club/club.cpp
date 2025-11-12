#include<bits/stdc++.h>
#define L(i,j,k) for(int i=(j);i<=(k);++i)
#define R(i,j,k) for(int i=(j);i>=(k);--i)
#define lb(x) (x&-x)

namespace rsy {
using namespace std;
using i64 = long long;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
void chmax (int &x, int c) { x = max(x, c); }
void chmin (int &x, int c) { x = min(x, c); }

const int maxn = 1e5 + 10, mod = 998244353;
int N, A[maxn][3], rk[maxn][3], cnt[3], val[maxn];
pii p[3];

void solve() {
	cin >> N; L (i, 1, N) L (j, 0, 2) cin >> A[i][j];
	L (i, 1, N) {
		L (j, 0, 2) p[j].first = A[i][j], p[j].second = j;
		sort (p, p + 3, greater<pii>());
		L (j, 0, 2) rk[i][j] = p[j].second;
	}
	L (i, 1, N) L (j, 0, 2) assert (0 <= rk[i][j] && rk[i][j] < 3);
	L (i, 0, 2) cnt[i] = 0;
	ll res = 0; L (i, 1, N) cnt[rk[i][0]]++, res += A[i][rk[i][0]];
	int pos = -1; L (i, 0, 2) if (cnt[i] > N / 2) pos = i;
	if (pos == -1) return cout << res << '\n', void();
	int id = 0; L (i, 1, N) if (rk[i][0] == pos) val[++id] = A[i][rk[i][0]] - A[i][rk[i][1]];
	sort (val + 1, val + 1 + id);
	L (i, 1, cnt[pos] - N / 2) res -= val[i];
	cout << res << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1; cin >> T;
	while (T--) solve();
	return 0;
}
} signed main() {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	return rsy::main();
}
// 0.1s 3MB
