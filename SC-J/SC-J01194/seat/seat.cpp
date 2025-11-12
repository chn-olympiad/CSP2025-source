#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int a[1000005];
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int o = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	int x = 1, y = 0;
	int op = 1;
	for (int i = 1; i <= n * m; i++) {
		y += op;
		if (y > n) {
			x++;
			y = n;
			op = -1;
		}
		else if (y < 1) {
			x++;
			y = 1;
			op = 1;
		}
		if (o == a[i]) {
			cout << x << ' ' << y << '\n';
			return 0;
		}
	}
	return 0;
}