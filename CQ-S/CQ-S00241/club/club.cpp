#include <bits/stdc++.h>
using namespace std;
long long t, n, b[1000005], ans1, ans2, ans3, maxn, f[1000005];
struct st{
	long long x, y, z;
}a[1000005];
void fun(long long x) {
	if (x == n + 1) {
		long long ans = 0;
		for (long long i = 1; i <= n; i++) {
			ans += b[i];
		}
		maxn = max(maxn, ans);
		return;
	}
	for (long long i = 1; i <= 3; i++) {
		if (ans1 < n / 2) {
			ans1++;
			b[x] = a[x].x;
			fun(x + 1);
			ans1--;
		}
		if (ans2 < n / 2) {
			ans2++;
			b[x] = a[x].y;
			fun(x + 1);
			ans2--;
		}
		if (ans3 < n / 2) {
			ans3++;
			b[x] = a[x].z;
			fun(x + 1);
			ans3--;
		}
	}
}
bool cmp(st l, st r) {
	return l.x > r.x;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		bool f = 1;
		for (long long i = 1; i <= n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].z;
			if (a[i].y != 0 || a[i].z != 0) {
				f = 0;
			}
		}
		if (f) {
			sort (a + 1, a + n + 1, cmp);
			long long ans = 0;
			for (long long i = 1; i <= n / 2; i++) {
				ans += a[i].x;
			}
			cout << ans << '\n';
			continue;
		}
		ans1 = 0, ans2 = 0, ans3 = 0, maxn = 0;
		fun(1);
		cout << maxn << '\n';
	}
	return 0;
}
