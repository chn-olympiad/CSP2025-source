#include <bits/stdc++.h>
#define int long long
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, r, l) for (int i = (r); i >= (l); --i)
#define fs first
#define sc second
#define ls (u << 1)
#define rs (u << 1 | 1)
#define mid ((l + r) >> 1)
#define lc ls, l, mid
#define rc rs, mid + 1, r
#define gc getchar
#define pc putchar

using namespace std;
using pii = pair<int, int>;

const int maxn = 1e6 + 10;
const bool multidata = 1;

template<typename T = int>
T read() {
	int x = 0, f = 1;
	char c = gc();
	while (c < '0' || c > '9') {
		if (c == '-') f = -f;
		c = gc();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = gc();
	}
	return x * f;
}

template<typename T = int>
void write(T x) {
	if (x < 0) pc('-'), x = -x;
	if (x >= 10) write(x / 10);
	pc(x % 10 + '0');
}

struct node {
	int i, j, val;
	node() = default;
};

int n, ans;
pii a[maxn][4];
int cnt[4];

void fake_main() {
	n = read();
	rep(i, 1, n) {
		int pos = 0;
		rep(j, 1, 3) a[i][j] = {read(), j};
		sort(a[i] + 1, a[i] + 4, greater<pii>());
		++cnt[a[i][1].sc], ans += a[i][1].fs;
	}
	int x = 0;
	rep(i, 1, 3) if (cnt[i] > n / 2) x = i;
	if (!x) {
		write(ans), pc('\n');
		return;
	}
	vector<int> cur;
	rep(i, 1, n) if (a[i][1].sc == x) cur.push_back(a[i][1].fs - a[i][2].fs);
	sort(cur.begin(), cur.end());
	rep(i, 1, cnt[x] - n / 2) ans -= cur[i - 1];
	write(ans), pc('\n');
}

void real_clear() {
	cnt[1] = cnt[2] = cnt[3] = ans = 0;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T = multidata ? read() : 1;
	while (T--) fake_main(), real_clear();
	return 0;
}

