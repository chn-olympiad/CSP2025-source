#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
#define csep constexpr
#define empb emplace_back
csep i32 inf32 = 0x3f3f3f3f;

// ---------------------------------------------------------------

csep i32 MAXN = 1e5 + 5;
i32 n, a[MAXN][3], cnt[3], bel[MAXN];
i64 ans;

inline i32 rst(i32 x, i32 k) {
	i32 val[3] = {a[x][k] - a[x][0], a[x][k] - a[x][1], a[x][k] - a[x][2]};
	val[k] = inf32;
	return min({val[0], val[1], val[2]});
}

inline void init() {
	for (i32 i = 0; i <= n; ++i)
		a[i][0] = a[i][1] = a[i][2] = bel[i] = 0;
	cnt[0] = cnt[1] = cnt[2] = 0;
	ans = 0;
}
inline int mian() {
	cin >> n;
	for (i32 i = 1; i <= n; ++i) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		i32 mx = max({a[i][0], a[i][1], a[i][2]});
		ans += mx;
		if (mx == a[i][0])
			++cnt[0], bel[i] = 0;
		else if (mx == a[i][1])
			++cnt[1], bel[i] = 1;
		else
			++cnt[2], bel[i] = 2;
	}
	i32 k = -1;
	if (cnt[0] > (n >> 1))
		k = 0;
	else if (cnt[1] > (n >> 1))
		k = 1;
	else 
		k = 2;
	if (k == -1) {
		cout << ans << '\n';
		return 0;
	}
	i32 lkc = cnt[k] - (n >> 1);
	vector<i32> lk;
	for (i32 i = 1; i <= n; ++i)
		if (bel[i] == k)
			lk.empb(rst(i, k));
	nth_element(lk.begin(), lk.begin() + lkc, lk.end());
	for (i32 i = 0; i < lkc; ++i)
		ans -= lk[i];
	cout << ans << '\n';
	return 0;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	i32 T;
	cin >> T;
	while (T--)
		init(), mian();
	fflush(stdout);
	return 0;
}