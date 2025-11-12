#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int r;
	cin >> r;
	vector<int> pers(n * m - 1);
	for (int &i : pers) {
		cin >> i;
	}
	sort(pers.begin(), pers.end(), greater<int>());
	int x = 1, y = 1;
	int flag = 1;
	for (const int &i : pers) {
		if (i < r) {
			cout << x << ' ' << y << endl;
			return 0;
		}
		y += flag;
		if (y <= 0 || y > n) {
			flag *= -1;
			y += flag;
			x++;
		}
	}
	cout << x << ' ' << y << endl;
	return 0;
}
