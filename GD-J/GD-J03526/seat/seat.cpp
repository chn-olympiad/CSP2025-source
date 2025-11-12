#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, a[20005], s, mid, l, r, hang, lie;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	s = a[1];
	sort(a + 1, a + 1 + n * m);
	l = 1;
	r = n * m + 1;
	while(l <= r) {
		mid = (l + r) / 2;
		if(a[mid] == s) {
			s = mid;
			break;
		} else if(a[mid] < s) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	s = n * m - s + 1;
	lie = s / (n * 2) * 2 + 1 - (s % (n * 2) == 0 ? 1 : 0) * 2;
	s %= n * 2;
	if(s == 0) {
		s = n * 2;
	}
	if(s <= n) {
		hang = s;
	} else {
		lie++;
		hang = 2 * n - s + 1;
	}
	cout << lie << " " << hang << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
