#include<bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5, M = 15;

int n, m, r;
int a[N], b[M][M];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n * m; ++i) scanf("%d", &a[i]);
	
	r = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	
	int sz = 1;
	bool flag;
	for(int i = 1, j = 1; i <= n; ++i) {
		flag = (i % 2 == 0);
		if(flag) j = m;
		else j = 1;
		for(j; ; ) {
			b[i][j] = a[sz++];
			if(flag) j--;
			else j++;
			if(j < 1 || j > m) break;
		}
	}
	
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(b[i][j] == r) return printf("%d %d", i, j), 0;
		}
	}
	return 0;
}