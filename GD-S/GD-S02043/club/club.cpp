#include <bits/stdc++.h>
using namespace std;
struct stu {
	int a1, a2, a3, wei;
} a[100010];
int n, t;
bool cmp(stu x, stu y) {
	return x.wei > y.wei;
}
int b[10];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		memset(b, 0, sizeof(b)); 
		cin >> n;
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
			int mn = min(a[i].a1, min(a[i].a2, a[i].a3));
			int mx = max(a[i].a1, max(a[i].a2, a[i].a3));
			int mi = a[i].a1 + a[i].a2 + a[i].a3 - mn - mx;
			a[i].wei = mx - mi;
		}
		sort(a + 1, a + n + 1, cmp);
		for (int i = 1; i <= n; i++) {
			int mn = min(a[i].a1, min(a[i].a2, a[i].a3));
			int mx = max(a[i].a1, max(a[i].a2, a[i].a3));
			int mi = a[i].a1 + a[i].a2 + a[i].a3 - mn - mx;
			int xx, yy;
			if (a[i].a1 == mx) xx = 1;
			else if (a[i].a2 == mx) xx = 2;
			else if (a[i].a3 == mx) xx = 3;
			
			if (a[i].a1 == mi && xx != 1) yy = 1;
			else if (a[i].a2 == mi && xx != 2) yy = 2;
			else if (a[i].a3 == mi && xx != 3) yy = 3;
			if (b[xx] < n / 2) ans += mx, b[xx]++;
			else ans += mi, b[yy]++;
		}
		cout << ans << '\n';
	}
	return 0;
}
