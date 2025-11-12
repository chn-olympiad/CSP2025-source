#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 200 + 10;
struct node {
	int V, id;
} b[maxn];
int tot;
bool cmp (node a, node b) {
	return a.V > b.V;
}
int main () {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n * m; i ++) {
		tot ++;
		b[tot].id = i;
		cin >> b[tot].V;
	} sort(b + 1, b + tot + 1, cmp);
	int pos = 0;
	for (int i = 1; i <= tot; i ++) {
		if (b[i].id == 1) {
			pos = i;
			break;
		}
	}
	int c = (pos + n - 1) / n, r = 0, tmp = pos % n;
	if (tmp == 0) tmp = n;
	if (c % 2 == 1) {
		r = tmp;
	} else {
		r = n - tmp + 1;
	}
	cout << c << ' ' << r;
	return 0;
}
