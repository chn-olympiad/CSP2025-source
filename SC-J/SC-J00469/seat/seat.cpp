#include <cstdio>
#include <algorithm>
const int N = 15;
struct Node {
	int a, id;
	bool operator < (const Node &rhs) const {
		return a > rhs.a;
	}
};
Node a[N * N];
int n, m;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n * m; i++) {
		scanf("%d", &a[i].a);
		a[i].id = i;
	}
	std::sort(a + 1, a + n * m + 1);
	int x = 1, y = 1;//列，行
	for(int i = 1; i <= n * m; i++) {
		if(a[i].id == 1) {
			printf("%d %d\n", x, y);
			break;
		}
		if(x & 1) {
			if(y < n) y++;
			else x++;
		} else {
			if(y > 1) y--;
			else x++;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}