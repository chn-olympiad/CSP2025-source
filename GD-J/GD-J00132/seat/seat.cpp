#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1000];
int r[10000], cnt = 0;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if(i == 1) {
			cnt = a[i];
		}
	}
	sort(a + 1, a + 1 + n * m, cmp);
	int x = 1, y = 1;
	int u = 1;
	if(a[u] == cnt) {
		cout << 1 << " " << 1;
		return 0;
	}
	while(u <= n * m && a[u] != cnt) {
		if(y % 2 == 1) {
			x++;
			if(x > n) {
				x = n;
				y++;
			}
			u++;
		}
		else{
			x--;
			if(x == 0) {
				x = 1;
				y++;
			}
			u++;
		}
	}
	cout << y << " " << x;
	return 0;
}
