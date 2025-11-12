#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
struct node {
	int x, y, z;
}a[N];
struct str {
	int x, y, idx, idy;
}b[N];
int n, cnt[5];
int max3(int x, int y, int z) {
	return max(max(x, y), z);
} 
int cimax(int x, int y, int z) {
	if (x == y && y == z) return x;
	int maxx = max3(x, y, z), minn = min(min(x, y), z);
	if (x == y && x == maxx) return x;
	if (x == z && x == maxx) return x;
	if (z == y && y == maxx) return y;
	if (x > minn && x < maxx) return x;
	if (y > minn && y < maxx) return y;
	if (z > minn && z < maxx) return z;
}
int idcimax(int x, int y, int z) {
	if (x == y && y == z) return 1;
	int maxx = max3(x, y, z), minn = min(min(x, y), z);
	if (x == y && x == maxx) return 2;
	if (x == z && x == maxx) return 3;
	if (z == y && y == maxx) return 3;
	if (x > minn && x < maxx) return 1;
	if (y > minn && y < maxx) return 2;
	if (z > minn && z < maxx) return 3;
}
void ycl(int id, int x, int y, int z) {
	b[id].x = max3(x, y, z);
	b[id].y = cimax(x, y, z);
	int idid = 0;
	if (x == b[id].x) idid = 1;
	else if (y == b[id].x) idid = 2;
	else idid = 3;
	b[id].idx = idid;
	b[id].idy = idcimax(x, y, z);
}
bool cmp(str a, str b) {
	if (a.x - a.y == b.x - b.y) {
		return a.x > b.x;
	}
	return a.x - a.y > b.x - b.y;
}
void solve() {
	memset(cnt, 0, sizeof cnt);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].x >> a[i].y >> a[i].z;
		ycl(i, a[i].x, a[i].y, a[i].z);
	}
	int ans = 0;
	sort(b + 1, b + n + 1, cmp);
	for (int i = 1; i <= n; ++i) {
		if (b[i].x == b[i].y) {
			ans += b[i].x;
			continue;
		}
		if (cnt[b[i].idx] >= n / 2) {
			ans += b[i].y;
			if (b[i].idy != 0) cnt[b[i].idy]++;
		}
		else {
			ans += b[i].x;
			if (b[i].idx != 0) cnt[b[i].idx]++;
		}
	}
	cout << ans << '\n';
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
