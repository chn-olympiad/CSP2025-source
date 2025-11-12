#include <bits/stdc++.h>

using namespace std;

//struct V {
//	int data;
//	int idx;
//};

int n, m, ans[20][20], top = -1, r_f;
int fen[110]; 
// n, m <= 10

bool cmp (int x, int y) {
	return x > y;
}

int main () {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> fen[i];
	}
	r_f = fen[1];
	sort(fen + 1, fen + n * m + 1, cmp);
	top = 1;
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= n; j++) {
				ans[j][i] = fen[top++];
			}
		} else {
			for (int j = n; j >= 1; j--) {
				ans[j][i] = fen[top++];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
//			cout << ans[i][j] << " ";
			if (ans[i][j] == r_f) {
				cout << j << " " << i;
				return 0;
			}
		}
//		cout << endl;
	}
//	cout << "r_f = " << r_f;
	return 0;
} 
