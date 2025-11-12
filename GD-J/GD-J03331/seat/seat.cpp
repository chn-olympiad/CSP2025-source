#include <bits/stdc++.h>
using namespace std;
int a[105];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int s = n * m;
	for (int i = 1; i <= s; i++) {
		cin >> a[i];
	}
	int x = a[1], pl;
	sort(a + 1, a + s + 1, greater<int>());
	for (int i = 1; i <= s; i++) {
		if (a[i] == x) {
			pl = i;
		}
	}
	int shang = pl / n, yu = pl % n;
	if (shang % 2 == 0) {
		if (yu == 0) {
			cout << shang << " " << 1; 
		} else {
			cout << shang  + 1 << " " << yu;
		}
	} else {
		if (yu == 0) {
			cout << shang << " " << n;
		} else {
			cout << shang + 1 << " " << n - yu + 1;
		}
	}
	return 0;
}
