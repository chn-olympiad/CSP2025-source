#include <iostream>
#include <vector>

#define N 10001

using namespace std;

int t, n, sa;
int a[N][4];
int seq[3][N];

/* void check(int k) {
	int cap = 0;

	for (int j = 1; j < n; j++) {
		cap++;
		if (cap == 
		a[j][k];
	}
} */

int main() {
	auto _1 = freopen("club.in", "r", stdin);
	auto _2 = freopen("club.out", "w", stdout);

	cin >> t;

	for (int i = 1; i <= t; i++) {
		cin >> n;

		for (int j = 1; j <= n; j++) {
			cin >> a[j][1] >> a[j][2] >> a[j][3];
			int cur_sa = max(a[j][1], max(a[j][2], a[j][3]));
			// check();
			sa += cur_sa;
		}

		cout << sa << endl;
		sa = 0;
	}

	return 0;
}
