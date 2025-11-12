#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<int> a;
int chushi;
bool cmp(int k1, int k2) {
	return k1 > k2;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n * m; ++i) {
		int x; cin >> x;
		a.push_back(x);
	}
	chushi = a[0];
	int zw = 0;
	sort(a.begin(), a.end(), cmp);
	for (int i = 0; i < n * m; ++i) {
		if (chushi == a[i]) {
			zw = i + 1;
			break;
		}
	}
	int y = (int)ceil(zw * 1.0 / n);
	int x = 0;
	if (y % 2 == 0) {
		int j = zw % n;
		if (j != 0)
			x = n - j + 1;
		else 
			x = 1;
	}
	else {
		x = (zw % n == 0) ? n : zw % n;
	}
	cout << y << ' ' << x;
}
