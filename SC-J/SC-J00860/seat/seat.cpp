#include<bits/stdc++.h>
using namespace std;
const int N = 15;
int n, m, seat[N*N], mark[N*N], R, lie, hang;
int cmp(int a, int b) {
	return a > b;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> seat[i];
	R = seat[1];
	sort(seat + 1, seat + 1 + n * m, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (seat[i] == R) {
			int a = i % n, b = i / n;
			if (i % n == 0) {
				a = n;
				b = i / n - 1;
			}
			if (b % 2 == 0)hang = a;
			else hang = n - a + 1;
			lie = b + 1;
			cout << lie << " " << hang;
		}
	}
	return 0;
}