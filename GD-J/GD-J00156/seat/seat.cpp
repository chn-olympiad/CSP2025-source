#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[110];
bool cmp(int f, int s) {
	return f > s;
}

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	
	int R;
	for (int i = 1; i <= n * m; i ++) {
		cin >> a[i];
		if (i == 1) R = a[i];
	}
	sort(a + 1, a + n * m + 1, cmp);
	
	int cnt = 1;
	for (int j = 1; j <= m; j ++) {
		if (j % 2 == 1) {
			for (int i = 1; i <= n; i ++) {
				if (a[cnt] == R) {
					cout << j << " " << i << endl;
					return 0;
				}
				cnt ++;
			}
		} else {
			for (int i = n; i >= 1; i --) {
				if (a[cnt] == R) {
					cout << j << " " << i << endl;
					return 0;
				}
				cnt ++;
			}
		}
	}
	
	return 0;
}
