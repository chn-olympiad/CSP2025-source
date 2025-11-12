#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int n, m, a[N], ans, h, l;
inline bool cmp(int x, int y) {
	return x > y;
}
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	ans = a[1];
	sort(a + 1, a + 1 + n * m, cmp);
	l = 1, h = 1;
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == ans) {
			cout << l << " " << h;
			break;
		} 
		if (l & 1) {
			++h;
			if (h > n) h = n, l++;
		}
		else {
			--h;
			if (h == 0) h = 1, l++;
		}
	}
	return 0;	
}
