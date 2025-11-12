//GZ-S00306 贵阳市云城中学 王乾隆
#include <bits/stdc++.h>
#define X first
#define Y second
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
using namespace std;
using ll = long long int;
using ull = unsigned long long int;
using ld = double;
using pii = pair<int, int>;
constexpr int maxn = 4e5 + 10, mod = 998244353;
int T, n, d[5]; pii a[maxn][4]; int b[maxn];
void solve() {
	scanf("%d", &n); d[1] = d[2] = d[3] = 0;
	rep(i, 1, n) scanf("%d%d%d", &a[i][1].X, &a[i][2].X, &a[i][3].X), a[i][1].Y = 1, a[i][2].Y = 2, a[i][3].Y = 3;
	rep(i, 1, n) sort(a[i] + 1, a[i] + 4); 
	ll ans = 0; int k = 0;
	rep(i, 1, n) { 
		ans += a[i][3].X;
		++d[a[i][3].Y];
	}
	int p = 0;
	rep(i, 1, 3) if (d[i] > n / 2) p = i;
	if (!p) { printf("%lld\n", ans); return; }
	// cout << "qwq:" << ans << "\n";
	rep(i, 1, n) if (a[i][3].Y == p) b[++k] = a[i][3].X - a[i][2].X; //, cout << i << " " << b[k] << "\n";
	// 接下来考虑将 p 移动
	// 考虑将最多的那位减少到 n / 2 以下，显然是 a[i][3].X - a[i][2].X 排序选
	// 显然不会有新的大于 n / 2 的产生，纯种诈骗题 
	// cout << "wtf:" << d[p] << "\n"; 
	sort(b + 1, b + k + 1);
	rep(i, 1, k) {
		if (d[p] <= n / 2) break;
		--d[p]; ans -= b[i];
	}
	printf("%lld\n", ans);
}
int main() {
 	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) solve();
	return 0;
}
/*
先贪一遍
令 c 是最多的出现的，按新贡献分别调整到 b 和 a
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
