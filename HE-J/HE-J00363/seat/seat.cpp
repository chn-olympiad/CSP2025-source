#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[110];

bool cmp(int a, int b) {return a > b;}

int main() {
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++) {
		cin >> a[i];
	}
	int cnt = a[1];

	sort (a + 1, a + n * m + 1, cmp);
	
	for (int i = 1; i <= n * m; i ++) {
		if (a[i] == cnt) {
//			cout << i << '\n';
			int cnt1 = i % n ,cnt2 = i / n;
			if (cnt1 == 0) cout << cnt2 << ' ' << n;
			else {
				if (cnt2 % 2 == 0) cout << cnt2 + 1 << ' ' << cnt1;
				else cout << cnt2 + 1 << ' ' << n - cnt1 + 1;
			}
		}
	}
	
	return 0;
}
/*
2 2
99 100 97 98
2 2
98 99 100 97
3 3
94 95 96 97 98 99 100 93 92
*/
