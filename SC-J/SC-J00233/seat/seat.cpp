#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 109;
int n, m, a[N], xr, xd;
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) cin >> a[i];
	xr = a[0];
	sort(a, a + n * m, greater<int>());
	for (int i = 0; i < n * m; i++)
		if (a[i] == xr) {
			xd = i;
			break;
		}
	int lie = (xd / n) + 1;
	cout << lie << ' ';
	if (lie & 1) cout << (xd % n) + 1;
	else cout << n - (xd % n);
}