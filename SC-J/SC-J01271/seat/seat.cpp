#include<bits/stdc++.h>
using namespace std;
int a[1010], res = 0;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	res = a[1];
	sort(a + 1, a + n * m + 1, greater<int>());
	for(int i = 1; i <= n * m; i++) {
		if(a[i] == res) {
			res = i;
			break;
		}
	}
	int t = res / n;
	if(t % 2 == 0) {
		if(res % n == 0) {
			cout << t << " " << 1;
		} else cout << t + 1 << " " << res - t * n;
	} else {
		if(res % n == 0) {
			cout << t << " " << n;
		} else cout << t + 1 << " " << m - (res - t * n) + 1;
	}
}


