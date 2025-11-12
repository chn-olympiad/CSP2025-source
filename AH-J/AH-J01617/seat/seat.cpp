#include<bits/stdc++.h>
using namespace std;
const int N = 1e7;
typedef long long ll;
ll a[N], b[15][15];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ll n, m, ans;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	ans = a[1];
	sort(a + 1, a + n * m + 1);
	for (int i = n * m; i >= 1; i--) {
		if (a[i] == ans) {
			ans = n * m - i + 1;
		}
	}
	int j = ceil(ans * 1.00 / (n * 1.00)), i;
	if (j % 2 == 0) {
		i = n - ans % n + 1;
	} else {
		if (ans % n == 0) {
			i = n;
		} else {
			i = ans % n;
		}
	}
	cout << j << " " << i;
	return 0;
}
