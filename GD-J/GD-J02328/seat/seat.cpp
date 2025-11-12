#include <bits/stdc++.h>

using namespace std;

const int N = 15;
const int M = 110;
int a[M];

int cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, d;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	d = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	int pos;
	for(int i = 1; i <= n * m; i++) {
		if(a[i] == d) {
			pos = i;
			break;
		}
	}
	int j = 1, k = 0;
	for(int i = 1; i <= m; i++) {
		int mn = (i - 1) * n + 1;
		int mx = i * n; 
		if(pos >= mn && pos <= mx) {
			cout << i << ' ';
			int r = pos % n;
			if(r == 0) r = n;
			if(i % 2 == 1) {
				cout << r;
			} else {
				cout << n - r + 1;
			}
			break;
		}
	}
	return 0;
}
