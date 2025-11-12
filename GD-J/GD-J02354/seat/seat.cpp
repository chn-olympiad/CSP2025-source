#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int a[N];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> a[i];
	}
	int R = a[0];
	sort(a, a + n * m, greater<int>());
	int idx = -1; 
	for (int i = 0; i < n * m; i++) {
		if (a[i] == R) idx = i;
	}
	cout << idx / n + 1 << " ";
	if ((idx / n + 1) % 2 == 1) {
		cout << idx % n + 1;
	} else {
		cout << n - idx % n;
	}
	// << ((idx / n + 1) % 2 == 1)? idx % n + 1 : idx % n + 1
	return 0;
} 
