#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	vector<int> mgs(n);
	for (int &i : mgs) {
		cin >> i;
	}
	if (n < 3) {
		cout << 0;
	} else if (n == 3) {
		int h = 0, mx = -1;
		for (int i = 0; i < n; i++) {
			h += mgs[i];
			mx = max(mx, mgs[i]);
		}
		if (h > mx * 2) {
			cout << 1;
		} else {
			cout << 0;
		}
	}
	return 0;
}
