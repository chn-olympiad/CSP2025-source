//I want to see myself at luogu
// my luogu id:993044
// my luogu name:Like_Amao
//91
//78
//13
//169
//100 + 100 + 25 + 40 = 265 pts
#include <bits/stdc++.h>
using namespace std;
const int N = 21;
int a[N][N], b[N * N];
bool cmp(int, int);
int read();
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n = read(), m = read();
	for (int i = 1 ; i <= n * m ; i ++) {
		b[i] = read();
	}
	int t = b[1];
	int cnt = 0;
	int x = 1, y = 1;
	sort(b + 1, b + n * m + 1, cmp);
	int turn = 1;
	while (cnt <= n * m) {
		if (turn == 1) {
			a[x][y] = b[++ cnt];
			if (x == n) {
				y ++;
				turn = 2;
			}
			else {
				x ++;
			}
		}
		else if (turn == 2) {
			a[x][y] = b[++ cnt];
			if (x == 1) {
				y ++;
				turn = 1;
			}
			else {
				x --;
			}
		} 
	}
	for (int i = 1 ; i <= n ; i ++) {
		for (int j = 1 ; j <= m ; j ++) {
			if (a[i][j] == t) {
				cout << j << " " << i;
				return 0;
			}
		}
	}
	return 0;
}
bool cmp(int x, int y) {
	return x > y;
}
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') {
			f = -1;
		}
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = (x << 1) + (x << 3) + (ch - '0');
		ch = getchar();
	}
	return x * f;
}
