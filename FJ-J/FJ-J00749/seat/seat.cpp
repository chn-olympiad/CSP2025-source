#include <bits/stdc++.h>
using namespace std;
int a[10005], b[10005];
int cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, lie, hang, ans;
	cin>>n>>m;
	for (int i = 0; i < n * m; i++) {
		cin>>a[i];
	}
	for (int i = 0; i < n * m; i++) {
		b[i] = a[i];
	}
	sort(b, b + n * m, cmp);
	for (int i = 0; i < n * m; i++) {
		if (b[i] == a[0]) {
			ans = i + 1;
			break;
		}
	}
	lie = ans / n + 1;
	if (ans % n == 0) lie--;
	if (lie % 2 == 1) {
		hang = ans % lie;
		if (ans % lie == 0) hang = n;
	}
	else {
		hang = n + 1 - ans % lie;
		if (ans % lie == 0) hang = 1;
	}
	cout<<lie<<' '<<hang;
	return 0;
}
