#include<bits/stdc++.h>
using namespace std;
int arr[110];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m, n, cnt = 0, m1, n1;
	cin >> n >> m;
	for (int i = 0; i < m * n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i < m * n; i++) {
		if (arr[i] > arr[0]) {
			cnt++;
		}
	}
	cnt++;
	if (cnt <= n) {
		cout << 1 << " " << cnt;
		return 0;
	} else {
		if (cnt % n == 0) {
			m1 = cnt / n ;
		} else {
			m1 = cnt / n + 1;
		}
		if (cnt % n == 0) {
			n1 = n;
			if (m1 % 2 == 0) {
				n1 = n - n1 + 1;
			}
		} else {
			n1 = cnt % n;
			if (m1 % 2 == 0) {
				n1 = n - n1 + 1;
			}
		}
	}
	cout << m1 << " " << n1;
	return 0;
}