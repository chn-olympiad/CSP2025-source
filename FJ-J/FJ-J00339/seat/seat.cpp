#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, a[N];
bool cmp(int A, int B) {
	return A > B;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	int k = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	int p = 0;
	for (int i = 1; i <= n * m; i++)
		if (k == a[i]) {
			p = i;
			break;
		}
	int c = (p % n == 0 ? (p / n) : (p / n + 1)), r = p - (c - 1) * n;
	if (c % 2 == 0) r = n - r + 1;
	cout << c << " " << r << "\n";
	return 0;
}

