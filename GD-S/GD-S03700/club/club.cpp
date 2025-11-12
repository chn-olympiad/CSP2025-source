#include<bits/stdc++.h>
using namespace std;
int n, b[100010], ans, cnta, cntb, cntc;
struct tt {
	int a, b, c;
	friend bool operator < (tt a, tt b) {
		return max(a.b, a.c) - a.a < max(b.b, b.c) - b.a;
	}
}a[100010];
priority_queue <tt> q;
void solve() {
	cin >> n;
	ans = cnta = cntb = cntc = 0;
	while (q.size()) q.pop();
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld%lld", &a[i].a, &a[i].b, &a[i].c);
		int maxx = max({a[i].a, a[i].b, a[i].c});
		if (a[i].a == maxx) b[i] = 1, cnta++;
		else if (a[i].b == maxx) b[i] = 2, cntb++;
		else b[i] = 3, cntc++;
		ans += maxx;
	}
	int bl = 0;
	if (cnta > n / 2) bl = 1;
	else if (cntb > n / 2) bl = 2;
	else if (cntc > n / 2) bl = 3;
	if (bl == 0) {
		cout << ans << "\n";
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (bl == 2) swap(a[i].b, a[i].a);
		else if (bl == 3) swap(a[i].c, a[i].a);
		if (bl == b[i]) {
			q.push(a[i]);
		}
	}
	while (q.size() > n / 2) {
		tt op = q.top();
		q.pop();
		ans = ans + max(op.b, op.c) - op.a;
	}
	cout << ans << "\n";
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
