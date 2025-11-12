#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
struct Mem {
	int a, b, c;
}a[N], aa1[N], aa2[N], aa3[N];
int n, cnt1, cnt2, cnt3, ans;
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].a >> a[i].b >> a[i].c;
	cnt1 = cnt2 = cnt3 = ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i].a >= a[i].b && a[i].a >= a[i].c) aa1[++cnt1] = a[i], ans += a[i].a;
		else if (a[i].b >= a[i].a && a[i].b >= a[i].c) aa2[++cnt2] = a[i], ans += a[i].b;
		else aa3[++cnt3] = a[i], ans += a[i].c;
	}
	if (cnt1 > n / 2) {
		int cha = cnt1 - n / 2;
		sort(aa1 + 1, aa1 + cnt1 + 1, [&](Mem x, Mem y) {return min(x.a - x.b, x.a - x.c) < min(y.a - y.b, y.a - y.c);});
		for (int i = 1; i <= cha; i++) ans -= min(aa1[i].a - aa1[i].b, aa1[i].a - aa1[i].c);
	}
	else if (cnt2 > n / 2) {
		int cha = cnt2 - n / 2;
		sort(aa2 + 1, aa2 + cnt2 + 1, [&](Mem x, Mem y) {return min(x.b - x.a, x.b - x.c) < min(y.b - y.a, y.b - y.c);});
		for (int i = 1; i <= cha; i++) ans -= min(aa2[i].b - aa2[i].a, aa2[i].b - aa2[i].c);
	}
	else if (cnt3 > n / 2) {
		int cha = cnt3 - n / 2;
		sort(aa3 + 1, aa3 + cnt3 + 1, [&](Mem x, Mem y) {return min(x.c - x.a, x.c - x.b) < min(y.c - y.a, y.c - y.b);});
		for (int i = 1; i <= cha; i++) ans -= min(aa3[i].c - aa3[i].a, aa3[i].c - aa3[i].b);
	}
	cout << ans <<"\n";
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T; cin >>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}
/*

*/
