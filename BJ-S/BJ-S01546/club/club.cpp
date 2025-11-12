#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N = 1000005, mod = 998244353;
int ar[N], col[N], dif[N];
void work() {
	int n;
	cin >> n;
	int cc[3] = {0, 0, 0};
	int res = 0;
	for (int i = 1; i <= n; i++) {
		int x0, x1, x2;
		cin >> x0 >> x1 >> x2;
		int mx = max({x0, x1, x2});
		res += mx;
		if (x0 == mx) {
			++cc[0], dif[i] = x0 - max(x1, x2);
			col[i] = 0;
		} else if (x1 == mx) {
			++cc[1], dif[i] = x1 - max(x0, x2);
			col[i] = 1;
		} else {
			++cc[2], dif[i] = x2 - max(x0, x1);
			col[i] = 2;
		}
	}
	int c = max_element(cc, cc + 3) - cc;
	int k = 0;
	for (int i = 1; i <= n; i++) {
		if (col[i] == c)
			ar[++k] = dif[i];
	}
	sort(ar + 1, ar + k + 1);
	for (int i = 1; i <= cc[c] - n / 2; i++)
		res -= ar[i];
	cout << res << '\n';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--)
		work();
	return 0;
}
