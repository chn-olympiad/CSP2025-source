#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, m;
int a[N];
bool cmp(int x, int y) {
	return x >= y;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int nm = n * m;
	for (int i = 1; i <= nm; i ++ ) cin >> a[i];
	int r = a[1];
	sort(a + 1, a + nm + 1, cmp);
	int x = 1, y = 1;
	for (int i = 1; i <= nm; i ++ ) {
		if (a[i] == r) {
			cout << y << ' ' << x;
			break;
		}
		if (y % 2 == 1) {
			if (x == n) y ++ ;
			else x ++ ;
		}else {
			if (x == 1) y ++ ;
			else x -- ;
		}
		//cout << y << ' ' << x << endl;
	}
	return 0;
}
