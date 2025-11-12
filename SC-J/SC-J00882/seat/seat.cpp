#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
#define int long long
int n, m, p, a[N], f;
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	f = a[1];
	sort(a + 1, a + 1 + n * m, greater<int>());
	for (int i = 1; i <= n * m; i++) if (a[i] == f) p = i;
	int l = p / n, q = p % n;
	if (q > 0) l++;
	else q = n;
	if (l % 2 == 1) cout << l << ' ' << q;
	else cout << l << ' ' << n - q + 1;
	return 0;
}