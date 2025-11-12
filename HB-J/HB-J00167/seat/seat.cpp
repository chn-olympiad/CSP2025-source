#include <bits/stdc++.h>
using namespace std;

int n, m, num, a[110];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	num = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1; i <= m; i++) {
		if(i % 2 == 1) {
			for(int j = 1; j <= n; j++) {
				if(a[(i - 1) * n + j] == num) {
					cout << i << " " << j;
					return 0;
				}
			}
		}else {
			for(int j = n; j >= 1; j--) {
				if(a[(i - 1) * n + (n - j + 1)] == num) {
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
