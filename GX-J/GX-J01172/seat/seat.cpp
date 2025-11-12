#include <bits/stdc++.h>
#define GXOI good
using namespace std;
const int N = 1e2 + 5;
int n, m, a[N], top;
int main () {
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++)
		cin >> a[i];
	top = 1;
	for (int i = 1; i <= n * m; i ++) {
		for (int j = i + 1; j <= n * m; j ++)
			if (a[i] < a[j]) {
				swap (a[i], a[j]);
				if (i == top)
					top = j;
				else if (j == top)
					top = i;
			}
	}
	//cout << top << endl;
	int ansi = 0;
	for (int i = 1; i <= n; i ++) {
		if (i % 2 == 1)
			for (int j = 1; j <= m; j ++) {
				ansi ++;
				if (ansi == top) {
					cout << i << " " << j << endl;
					return 0;
				}
			}
		else
			for (int j = m; j >= 1; j --) {
				ansi ++;
				if (ansi == top) {
						cout << i << " " << j << endl;
						return 0;
				}
			}
	}
	return 0;
}
