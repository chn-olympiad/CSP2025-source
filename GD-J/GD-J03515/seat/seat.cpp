#include<bits/stdc++.h>
using namespace std;
int n, m, a[105];
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int k = a[1], p;
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == k) {
			p = i;
			break;
		}
	}
	int l, h;
	if (p % n == 0) l = p / n;
	else l = p / n + 1;
	if (l % 2 == 1) {
		h = p % n;
		if (h == 0) h = n;
	} else {
		if (p % n == 0) h = 1;
		else h = n - p % n + 1;
	}
	cout << l << " " << h;
	return 0;
}
