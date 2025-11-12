#include<bits/stdc++.h>
using namespace std;
int n, m, a, s;
int c = 1, r = 1;
void move() {
	if (c % 2 == 1) {
		r++;
	}
	else {
		r--;
	}
	if (r < 1) {
		c++;
		r++;
	}
	else if (r > n){
		c++;
		r--;
	}
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1 && j == 1) {
				cin >> s;
			}
			else {
				cin >> a;
				if (a > s) {
					move();
				}
			}
		}
	}
	cout << c << " " << r << "\n";
	
	return 0;
}
