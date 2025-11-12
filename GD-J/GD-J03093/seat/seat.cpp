#include <bits/stdc++.h>
#define N 105

using namespace std;

int n, m, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, 1}, x, y, t, fx;

struct node { int id, wi; } a[N];

bool cmp(node p, node q) { return p.wi > q.wi; }

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	x = y = t = 1;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n * m; i++) {
		scanf("%d", &a[i].wi);
		a[i].id = i;
	}
	sort(a + 1, a + n * m + 1, cmp);
	while(1) {
		if(a[t].id == 1) {
			printf("%d %d", y, x);
			return 0;
		}
		while(x + dx[fx] <= n && x + dx[fx] > 0 && y + dy[fx] <= m && y + dy[fx] > 0) {
			x += dx[fx];
			y += dy[fx];
			t ++;
			if(a[t].id == 1) {
				printf("%d %d", y, x);
				return 0;
			}
		}
		fx = (fx + 1) % 4;
	}
	return 0;
}
/*
100·Ö 
*/
