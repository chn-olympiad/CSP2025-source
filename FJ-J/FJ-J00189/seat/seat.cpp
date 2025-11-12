#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	freopen("seat.in", "r", stdin); freopen("seat.out", "w", stdout); cin.tie(0); cout.tie(0);
	int n, m, s; cin >> n >> m; int a[n * m];
	for (int i = 0; i < n * m; i++) {
		cin >> a[i];
	}
	s = a[0]; sort(a, a + n * m, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i - 1] == s) {s = i;break;}
	}
	cout << s << endl;
	if ((s / m) % 2 == 1) {
		cout << s / n << ' ' << m - s % m;
	} else {
		cout << s / n + 1 << ' ' << s % m;
	}
	return 0;
}
