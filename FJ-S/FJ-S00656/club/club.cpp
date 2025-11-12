#include <bits/stdc++.h>
#define Write ios::sync_with_stdio(0);
#define by cin.tie(0);
#define Na1L0n9 cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int N = 1e5 + 10;
const int MOD = 998244353;
struct node {
	ll x, y, z;
} a[N];
ll T, n, cnt[3];
bool cmp(node x, node y) {
	ll pm = max({x.x, x.y, x.z}), qm = max({y.x, y.y, y.z});
	ll pn = x.x + x.y + x.z - pm - min({x.x, x.y, x.z}), qn = y.x + y.y + y.z - qm - min({y.x, y.y, y.z});
	return pm - pn > qm - qn;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	Write by Na1L0n9
	cin >> T;
	while (T--) {
		cin >> n;
		ll ans = 0;
		cnt[0] = cnt[1] = cnt[2] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].z;
		}
		sort(a + 1, a + n + 1, cmp);
		for (int i = 1; i <= n; i++) {
			if (a[i].x >= max(a[i].y, a[i].z)) {
				if (cnt[0] == n / 2) {
					ll tmp = max(a[i].y, a[i].z);
					ans += tmp;
					if (tmp == a[i].y) {
						cnt[1]++;
					}
					else {
						cnt[2]++;
					}
				}
				else {
					ans += a[i].x;
					cnt[0]++;
				}
			}
			else if (a[i].y >= max(a[i].x, a[i].z)) {
				if (cnt[1] == n / 2) {
					ll tmp = max(a[i].x, a[i].z);
					ans += tmp;
					if (tmp == a[i].x) {
						cnt[0]++;
					}
					else {
						cnt[2]++;
					}
				}
				else {
					ans += a[i].y;
					cnt[1]++;
				}
			}
			else {
				if (cnt[2] == n / 2) {
					ll tmp = max(a[i].x, a[i].y);
					ans += tmp;
					if (tmp == a[i].x) {
						cnt[0]++;
					}
					else {
						cnt[1]++;
					}
				}
				else {
					ans += a[i].z;
					cnt[2]++;
				}
			}
		}
		cout << ans << "\n";
		
	}
	return 0;
}

