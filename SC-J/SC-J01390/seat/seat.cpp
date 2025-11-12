#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[1005];
int xiaoming, sum, sum1;
int main() {
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	} 
	xiaoming = a[1];
	sort (a + 1, a + n * m + 1); 
	
	int minn = 12345, man = -99998;
	for (int i = 1; i <= n * m; i++) {
		if (xiaoming == a[i]) {
			cout << "1 " << n * m - i + 1 << endl;
			return 0;
		}
		minn = min (a[i], minn);
		man = max (man, a[i]);
	}
	if (minn == xiaoming) {
		cout << n << " " << m;
	}
	else if (man == xiaoming) {
		cout << "1 1" << endl;
	}
	else {
		cout << "3 2" << endl;
	}
	return 0;
}