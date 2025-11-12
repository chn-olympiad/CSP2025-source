#include<iostream>
#include<algorithm>
using namespace std;
int n, m;
int a[105];
bool cmp (int a, int b) {
	return a > b;
}
int main() {
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	int s = a[1];
	int k = 1;
	sort (a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n; i++) {
		if (i % 2 != 0) {
			for (int j = 1; j <= m; j++) {
				if (a[k++] == s) {
					cout << i << " " << j;
					break;
				}
			}
		}
		else {
			for (int j = m; j >= 1; j--) {
				if (a[k++] == s) {
					cout << i << " " << j;
					break;
				}
			}
		}
	}
	return 0;
}
