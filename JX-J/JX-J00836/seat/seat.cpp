#include<bits/stdc++.h>
using namespace std;

const int N = 1e2 + 10;
int n, m, a[N], num = 0, id = 0;

bool cmp(int i, int j) {
	return i > j;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	num = a[1];
	sort(a + 1, a + n * m + 1, cmp);
//	for (int i = 1; i <= n * m; i++) {
//		cout << a[i] << ' ';
//	}
//	cout << "\n";
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == num) {
//			cout << num << " " << a[i] << '\n';
			id = i;
			break;
		}
	}
//	cout << id << '\n';
	cout << (int)ceil(1.0 * id / m) << " ";
	if ((int)ceil(1.0 * id / m) % 2 != 0) {
		cout << (id % m == 0 ? m : id % m) << '\n';
	}
	else {
		cout << m - (id % m == 0 ? m : id % m) + 1 << '\n';
	}
	return 0;
}
