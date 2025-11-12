#include<bits/stdc++.h>
#define AC return 0
using namespace std;

int n, m, sum, t = 0, x, y, a1, a[1024];
double tmp;

bool cmp (int a, int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	sum = n * m;
	for (int i = 0; i < sum; i++)cin >> a[i];
	a1 = a[0];
	sort(a, a + sum, cmp);
	while (1) {
		if (a[t] == a1) {
			t++;
			break;
		} else t++;
	}
	tmp = (t * 1.0) / (n * 1.0);
	x = tmp;
	if (tmp - (x * 1.0) != 0) x++;
	if (x % 2) {
		if (t % n) y = t % n;
		else y = n;
	} else y = n - (t % n) + 1;
	cout << x << ' ' << y;
	AC;
}