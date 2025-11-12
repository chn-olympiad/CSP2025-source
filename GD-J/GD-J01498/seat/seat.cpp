#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, R = 0, cnt = 0;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			int a; scanf("%d", &a);
			if(i == 1 && j == 1) R = a;
			else if(a > R) cnt++;
		}
	}
	int c = cnt / n + 1;
	int r = (c & 1 ? cnt % n + 1 : n - cnt % n);
	printf("%d %d", c, r);
	return 0;
}

