#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], a1, x, y, aa, num;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++) {
		cin >> a[i];
	}
	a1 = a[1];
	sort(a+1, a+n*m+1);
	for (int i = n*m; i >= 0; i--) {
		++num;
		if (a[i] == a1) {
			aa = num;
		}
	}
	if(aa % n == 0) {
		x = aa/n;
	}
	else {
		x = aa/n+1;
	}
	if (x % 2 == 1) {
		y = aa - (n*(x-1));
	}
	else {
		y = n - (aa - (n*(x-1))) + 1;
	}
	cout << x << " " << y;
	return 0;
}
