#include <iostream>
#include <vector>

using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int num = 1;
	int g;
	cin >> g;
	for (int i = 1; i < n * m; i++) {
		int temp;
		cin >> temp;
		if (temp > g) {
			num++;
		}
	}
	int c = (num - 1) / n + 1;
	int r;
	if (c & 1 == 1) {
		r = num % n;
		if (r == 0) {
			r = n;
		}
	} else {
		r = n - num % n + 1;
		if (r > n) {
			r -= n;
		}
	}
	cout << c << ' ' << r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
