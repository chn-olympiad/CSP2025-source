#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
struct Node {
	int x, id;
	bool operator< (const Node B) const {
		return x > B.x;
	}
}a[N];
int n, m;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++)
		scanf("%d", &a[i].x), a[i].id = i;
	sort(a + 1, a + n * m + 1);
	int pos;
	for (int i = 1; i <= n * m; i++)
		if (a[i].id == 1) {
			pos = i;
			break;
		}
	int C = pos / n + (pos % n != 0);
	printf("%d ", C);
	if (C % 2) {
		if (pos % n == 0) printf("%d", n);
		else printf("%d", pos % n);
	} else {
		if (pos % n == 0) printf("%d", 1);
		else printf("%d", n - pos % n + 1);
	}
	return 0;
}
