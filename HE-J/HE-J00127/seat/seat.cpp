#include<bits/stdc++.h>
using namespace std;
int grades[110];
bool cmp(int x, int y) {
	if(x > y) return true;
	else return false;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, R_mark, R_seat_place;
	cin >> n >> m;
	int square = n * m;
	for(int i = 1; i <= square; i++) {
		cin >> grades[i];
	}
	R_mark = grades[1];
	sort(grades+1, grades+square+1, cmp);
//	cout << R_mark << endl;
//	for(int i = 1; i <= square; i++) {
//		cout << grades[i] << " ";
//	}
//	cout << endl;
	for(int i = 1; i <= square; i++) {
		if(grades[i] == R_mark) {
			R_seat_place = i;
//			cout << R_seat_place << endl;
			if(R_seat_place == 1) {
				cout << 1 << " " << 1;
				return 0;
			}
			break;
		}
	}
	int step = 0;
	for(int i = 1; i <= m; i++) {
		if(i % 2 == 1) {
			for(int j = 1; j <= n; j++) {
				step++;
				if(step == R_seat_place) {
					cout << i << " " << j;
					return 0;
				}
			}
		} else {
			for(int j = n; j >= 1; j--) {
				step++;
				if(step == R_seat_place) {
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}

	return 0;
}
