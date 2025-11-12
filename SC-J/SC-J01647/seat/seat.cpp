#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int a[N];
bool cmp(int x, int y) {
	return x > y;
}
int mp[N][N];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	cin >> a[1];
	int tmp = a[1];
	for (int i = 2; i <= n * m; i++) {
		cin >> a[i];
	}
	stable_sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (tmp == a[i]) {
			tmp = i;
			break;
		}
	}
	int cnt = 1;
	for (int j = 1; j <= m; j++) {
		if (j % 2 == 1) {
			int i = 1;
			while (i <= n) {
				if (cnt == tmp) {
					cout << j << " " << i << endl;
					return 0;
				}
				cnt++;
				i++;
			}
		} else {
			int i = n;
			while (i >= 1) {
				if (cnt == tmp) {
					cout << j << " " << i << endl;
					return 0;
				}
				cnt++;
				i--;
			}
		}
	}
	return 0;
}