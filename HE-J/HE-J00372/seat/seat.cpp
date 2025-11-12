#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int n, m;
struct Node {
	int x, id;
} a[N];
Node b[N];
bool cmp(Node a, Node b) {
	return a.x > b.x;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i].x;
		a[i].id = i;
	}
	sort(a + 1, a + n * m + 1, cmp);
	int nowx = 1, nowy = 1;
	int dir = 1;
	for (int i = 1; i <= n * m; i++) {
		int x = i % (n * 2);
		if (x > n)
			x = n - (x % n) + 1;
		b[a[i].id] = {x, (i + n - 1) / n};
	}
	cout << b[1].id << ' ' << b[1].x << '\n';
	return 0;
}
