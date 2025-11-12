#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
long long n, m, a[N], num;
bool cmp(long long x, long long y) {
	return x > y;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	num = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++)
		if (a[i] == num) {
			long long c = (i + n - 1) / n, r;
			if (c % 2 == 1)
				r = (i % n == 0 ? n : i % n);
			else
				r = (i % n == 0 ? 1 : n + 1 - (i % n));
			cout << c << " " << r;
			break;
		}
	return 0;
}
