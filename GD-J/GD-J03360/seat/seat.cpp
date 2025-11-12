#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1005;
ll n, m, s, a[maxn], x = 1, y = 1;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	s = a[1];
	sort(a + 1, a + n * m + 1, greater<ll>());
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == s) {
			cout << y << ' ' << x << '\n';
			return 0;
		}
		if ((x == 1 && y % 2 == 0) || (x == n && y % 2 == 1)) y++;
		else if (y % 2 == 0) x--;
		else x++;
	}
	return 0;
} 
