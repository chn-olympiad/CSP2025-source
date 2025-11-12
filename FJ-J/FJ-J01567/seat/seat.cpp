#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
int n = 0, m = 0;
struct NODE{
	int val;
	int num;
};
NODE a[N];

bool cmp(NODE A, NODE B) {
	return A.val > B.val;
}

void Put(int x, int y, int s, int op) {
	if (!(x >= 1 && x <= n && y >= 1 && y <= m)) {
		return;
	}
	if (a[s].num == 1) {
		cout << y << " " << x;
		return;
	}
	int nx = x + op;
	if (nx >= 1 && nx <= n) {
		Put(nx, y, s + 1, op);
	} else {
		Put(x, y + 1, s + 1, op * -1);
	}
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i].val;
		a[i].num = i;
	}
	sort(a + 1, a + n * m + 1, cmp);
	Put(1, 1, 1, 1);
	return 0;
}
