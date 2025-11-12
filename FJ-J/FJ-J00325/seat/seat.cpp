// 改了下面line40,没改上面line31,又卡半天 
// 100pts 
#include <iostream>
#include <algorithm>
using namespace std;
#define N 15

int seats[N][N], scores[N * N];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, R_score, cnt = 1;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++) {
		cin >> scores[i];
	}
	R_score = scores[1];
	for (int i = 1; i <= n * m; i ++) {
		for (int j = 1; j <= n * m - i; j ++) {
			if (scores[j + 1] > scores[j]) {
				swap(scores[j + 1], scores[j]);
			}
		}
	}
	for (int j = 1; j <= m; j ++) {
		if (j % 2 == 1) {
			for (int i = 1; i <= n; i ++) {
				seats[i][j] = scores[cnt];
				if (scores[cnt] == R_score) {
					cout << j << ' ' << i;
					return 0;
				}
				cnt ++;
			}
		} else if (j % 2 == 0) {
			for (int i = n; i >= 1; i --) {
				seats[i][j] = scores[cnt];
				if (scores[cnt] == R_score) {
					cout << j << ' ' << i;
					return 0;
				}
				cnt ++;
			}
		}
	}
	return 0;
}
// CSP-J2025 rp++!
