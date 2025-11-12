#include <bits/stdc++.h>
using namespace std;
bool cmp(int x, int y) {
	return x > y;
}
int a[11][11], b[110];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int c = 0, r = 0, ans = 0, b1 = 1;
	int n, m;
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++) {
		cin >> b[i];
	}	
	ans = b[1];
	
	sort(b + 1, b + 1 + n * m, cmp);
	
	for (int i = 1;i <= m;i++) {
		for (int j = 1;j <= n;j++) {
			a[i][j] = b[b1++];
		}
	}
	for (int i = 1;i <= m;i++) {
		for (int j = 1;j <= n;j++) {
			if(a[i][j] == ans) {
				c = i;
				if(i % 2 == 0) {
					r = n - j + 1;
				} else {
					r = j;
				}
				cout << c << " " << r;
				return 0;
			}
		}
	}
	return 0;
}
