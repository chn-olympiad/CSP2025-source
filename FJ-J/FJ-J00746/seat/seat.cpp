#include <bits/stdc++.h>

using namespace std;

int n, m, a[1000010], s, b, o, c, d;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m >> a[0];
	s = a[0];
	d = n * m;
	for (int i = 1; i < d; i++) {
		cin >> a[i];
	}
	sort(a, a + d, cmp);
	for (int i = 0; i < d; i++) {
		if (a[i] == s) o = i;
	}
	b = o / n, c = o % n;
	if (b & 1) {
		cout << b + 1 << " " << n - c;
	} else {
		cout << b + 1 << " " << c + 1;
	}
	cout << endl;
	
	return 0;
}

