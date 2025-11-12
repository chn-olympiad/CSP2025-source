#include <bits/stdc++.h>
using namespace std;

int scope[101];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m; 
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i) {
		cin >> scope[i];
	}
	int xiaohua = scope[1], id = -1;
	sort(scope + 1, scope + n * m + 1);
	for (int i = 1; i <= n * m; ++i) {
		if (scope[i] == xiaohua) {
			id = i;
		}
	}
	id = n * m - id + 1;
	clog << id;
	cout << (id - 1) / n + 1 << " " << (((id - 1) / n + 1) % 2 ? (id - 1) % n + 1 : n - ((id - 1) % n));
}
