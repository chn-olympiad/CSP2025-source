#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 15, MAXM = 15;
int n, m, grades[MAXN * MAXM];

bool cmp(int g1, int g2) {
	return g1 > g2;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n*m; ++i) {
		cin >> grades[i];
	}
	int r_grade = grades[1], r_index = 0;
	sort(grades + 1, grades + n*m + 1, cmp);
	int x = 1, y = 1, c = 1;
	for (int i = 1; i <= n*m; ++i) {
		if (c == 1 && y >= n + 1) {
			y = n;
			x++;
			c = -1;
		} else if (c == -1 && y <= 0) {
			c = 1;
			y = 1;
			x++;
		}
		if (grades[i] == r_grade) {
			cout << x << " " << y;
			return 0;
		}
		y += 1 * c;
	}
	return 0;
}
