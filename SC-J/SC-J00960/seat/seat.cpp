#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool cmp(int a, int b);

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int t = n * m;
	vector<int> a(t + 1);
	
	for (int i = 1; i <= t; ++i) {
		cin >> a[i];
	}
	
	int score = a[1], seat;
	
	sort(a.begin() + 1, a.end(), cmp);
	
	for (int i = 1; i <= t; ++i) {
		if (a[i] == score) {
			seat = i;
		}
	}
	
	int x, y;
	
	x = (seat - 1) / n + 1;
	y = seat % n;
	if (y == 0) {
		y = n;
	}
	
	if (x % 2 == 0) {
		y = n - y + 1;
	}
	
	
	cout << x << " " << y << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

bool cmp(int a, int b) {
	return a > b;
}