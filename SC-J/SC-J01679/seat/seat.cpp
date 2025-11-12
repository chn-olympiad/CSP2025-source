#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m, a[1005], k = 0;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	
	k = a[1];
	
	sort(a + 1, a + n * m + 1, [](int a, int b){return a > b;});
	
	int x = 0, y = 1, i = 0;
	while (x <= n && y <= m && a[i] != k) {
		i++;
		if (y & 1) {
			x++;
			if (x == n + 1) {
				x = n;
				y++;
			}
		}
		else {
			x--;
			if (x == 0) {
				x = 1;
				y++;
			}	
		}
	}
	
	cout << y << ' ' << x << '\n';
	
	return 0;
}