#include<bits/stdc++.h>
using namespace std;
long long n, x, cnt, m, ansx = 1, ansy = 1, sum;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m >> x;
	for (int i = 1; i < n * m; i++) {
		cin >> cnt;
		if (cnt > x) sum++;
	}
	for (;;) {
		sum -= m, ansy++;
		if (sum < 0) {
			sum += m;
			ansy--;
			break;
		}
	}
	if (ansy % 2 == 0) ansx = n - sum;
	else ansx = sum + 1;
	cout << ansy << " " << ansx;
	return 0;
}