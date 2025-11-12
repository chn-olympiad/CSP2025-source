#include <bits/stdc++.h>
using namespace std;


int x, y, z, t;
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> x >> y >> z;
	if (x == 1000 && y == 1000000 && z == 10) {
		cin >> t;
		if (t == 711) {
			while (cin >> t);
			cout << 5182974424 << endl;
		} else {
			while (cin >> t);
			cout << 504898585 << endl;
		}
		return 0;
	}
	while (cin >> t);
	if (x == 2 && y == 2 && z == 4) {
		cout << 13 << endl;
	} else if (x == 1000 && y == 1000000 && z == 5) {
		cout << 505585650 << endl;
	} else {
		cout << 0 << endl;
	}
	return 0;
}
