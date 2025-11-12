#include<bits/stdc++.h>
using namespace std;
int n, m, a[105];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i)	cin >> a[i];
	int small_r = a[1];
	sort(a + 1, a + 1 + n * m, greater<int>());
	int seat_r = lower_bound(a + 1, a + 1 + n * m, small_r, greater<int>()) - a;
	int ans_c = (seat_r + n - 1) / n, ans_r;
	if (seat_r % (2 * n) > 0 && seat_r % (2 * n) <= n){
		ans_r = seat_r % n;
		if (seat_r % n == 0)	ans_r = n;
	}
	else	ans_r = n - seat_r % n + 1;
	cout << ans_c << ' ' << ans_r;
	return 0;
}