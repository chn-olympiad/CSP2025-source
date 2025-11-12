#include<bits/stdc++.h>
using namespace std;
int n, m, i, j, k, x, y, c=1;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (i=1; i<n*m; i++) {
		scanf("%d", &x);
		c += x>k;
	}
	x = (c+n-1)/n;
	if (x&1) y = (c-1)%n+1;
	else y = n+1-((c-1)%n+1);
	printf("%d %d", x, y);
	return 0;
}

