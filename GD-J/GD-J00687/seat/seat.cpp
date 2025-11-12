//------------------------RP += INF!-------------------------------------
//RootSign, SqrtOne PLEASE GIVE ME POWER! 
#include<bits/stdc++.h>
using namespace std;
//2 2 99 100 98 97
//3 3 94 95 96 97 98 99 100 93 92
void solve() {
	int row, col;
	cin >> row >> col;
	vector<pair<int, bool>> a(row * col);
	int n = row * col;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first;
		a[i].second = (i == 0);
	}
	sort(a.begin(), a.end(), greater<pair<int, bool>>());
	/*
	1 8
	2 7 
	3 6
	4 5
	*/
	for (int i = 0; i < n; ++i) {
		if (a[i].second) {
			int curr = i + 1;
			int curr_row = (curr - 1) % row + 1;
			int curr_col = (curr + row - 1) / row;
			if (curr_col % 2 == 0) {
				cout << curr_col << " " << row - curr_row + 1;
			} else {
				cout << curr_col << " " << curr_row;
			}
		}
	}
}

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T = 1;
	while (T--) {
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
