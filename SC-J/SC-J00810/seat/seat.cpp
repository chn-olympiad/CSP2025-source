#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m, a[N];
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		int num;
		cin >> num;
		a[i] = num;
	}
	int r, rc, h, l;
	rc = a[1];
	sort(a + 1, a + n*m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == rc) r = i;
	}
	l = (r - 1) / n + 1;
	if (l % 2 == 1) {
		h = r - (l - 1) * n;
	} else {
		h = n - (r - (l - 1) * n) + 1;
	}
	cout << l << " " << h;
	return 0;
}