#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, m, p[N];
pair<int, int> pos[N];

bool cmp(const int &x, const int &y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++)
		scanf("%d", &p[i]);
	int g = p[1], R = 0;
	sort(p + 1, p + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++)
		if (p[i] == g) {
			R = i;
			break;
		}	
	int dx = 1, dy = 1, d = 0;
	for (int i = 1; i <= n * m; i++) {
	//	printf("%d %d\n", dx, dy);
		pos[i] = {dx, dy};
		if (!d) {
			if (dy < m) dy++;
			else dx++, dy = m, d = !d;
		} else {
			if (dy > 1) dy--;
			else dy = 1, dx++, d = !d;
 		}
	}	
	printf("%d %d", pos[R].first, pos[R].second);
	return 0;
} 
