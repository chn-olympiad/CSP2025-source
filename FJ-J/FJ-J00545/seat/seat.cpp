#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[110];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	
	for (int i = 1;i <= n * m; i ++) {
		cin >> a[i];
	}
	
	int x = a[1]; 
	sort(a + 1, a + n * m + 1, cmp);
	
	int y = 0;
	for (int i = 1; i <= n * m; i ++) {
		if (a[i] == x) {
			y = i;
		}
	}
	
	int c = 0;
	if (y % n != 0) {
		c = (y / n) + 1;
	} else {
		c = y / n;
	}
	
	cout << c << ' ';
	
	int d = (c - 1) * n;
	int ans = y - d;
	
	if (c % 2 != 0) {
		cout << ans;
	} else {
		cout << n - ans + 1;
	}
	
	return 0;
}
