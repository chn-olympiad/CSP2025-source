#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

//constexpr __uint128_t rp = -1;
const int N = 1e5;
int _TaSkS__;
int n, cnt1st, cnt2nd, cnt3rd;
int d1st[N+5], d2nd[N+5], d3rd[N+5];

void _Wo_rK__() {
	cnt1st = cnt2nd = cnt3rd = 0;
	LL ans = 0;
	cin >> n;
	for (int i = 1, a, b, c; i <= n; i++) {
		cin >> a >> b >> c;
		int mx = max(max(a, b), c);
		if (a == mx) d1st[++cnt1st] = mx - max(b, c);
		else if (b == mx) d2nd[++cnt2nd] = mx - max(a, c);
		else d3rd[++cnt3rd] = mx - max(a, b);
		ans += mx;
	}
//	cout << ans << ' ';
	if (cnt1st > n/2) {
		sort(d1st + 1, d1st + cnt1st + 1);
//		cout << "1st";
		for (int i = 1; i <= cnt1st - n/2; i++) ans -= d1st[i];
	}
	if (cnt2nd > n/2) {
		sort(d2nd + 1, d2nd + cnt2nd + 1);
//		cout << "2nd";
		for (int i = 1; i <= cnt2nd - n/2; i++) ans -= d2nd[i];
	}
	if (cnt3rd > n/2) {
		sort(d3rd + 1, d3rd + cnt3rd + 1);
//		cout << "3rd";
		for (int i = 1; i <= cnt3rd - n/2; i++) ans -= d3rd[i];
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> _TaSkS__;
	while (_TaSkS__--) _Wo_rK__();
	return 0;
}
/*
CSP-S2025T1
险些不会做，后面发现是一开始选最大值，再减去最大值与次大值的差的前 n/2 小。
假。
幸好结果与做 NOIP2024 T1 时差不多，我们发现一个颜色的数量太多了的话，就将其往颜色较小的颜色转移，这回是真的了。
若出现 d[i][j] 相同，可以任选。
15:28 AC。 
*/
