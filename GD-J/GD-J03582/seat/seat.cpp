#include <bits/stdc++.h>

using namespace std;

int a[200];
int n, m, id, cnt;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i) cin >> a[i];
	
	id = a[1]; 
	sort(a + 1, a + 1 + m * n, cmp);
	
	for (int i = 1; i <= m; ++i) {
		if (i & 1) {
			for (int j = 1; j <= n; ++j) {
				cnt += 1;
				if (a[cnt] == id) {
					cout << i << ' ' << j << '\n';
					return 0;
				}
			} 
		} else {
			for (int j = n; j >= 1; --j) {
				cnt += 1;
				if (a[cnt] == id) {
					cout << i << ' ' << j << '\n';
					return 0;
				}
			} 			
		}
	}
	
	return 0;
}

