#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 10;
struct Node {
	int val, id;
} a[N];
int n, m;

bool cmp(Node x, Node y) {
	return x.val > y.val;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i].val;
		a[i].id = i;
	}
	sort(a + 1, a + n * m + 1, cmp);
	int r = 1, c = 1;
	for (int i = 1; i <= n * m; i++) {
		if (a[i].id == 1)
			break;
		if (c % 2 == 1) {
			r++;
			if (r > n) {
				c++;
				r = n;
			}
		} else {
			r--;
			if (r < 1) {
				c++;
				r = 1;
			}
		}
	}
	cout << c << " " << r;
	return 0;
}
