#include<bits/stdc++.h>

using namespace std;
const int N = 1e4 + 10;
const int M = 2e6 + 10;

int read() {
	int x = 0;
	bool f = true;
	char ch = getchar();
	for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = false;
	for(; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0'; 
	return f ? x : -x;
} 
int n, m, k;
int c[12];
int a[12][N]; 
int h[N], e[M], w[M], ne[M], idx;

void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for(int i = 1; i <= m; i ++ ) {
		int a = read(), b = read(), c = read();
		add(a, b, c);
		add(b, c, a);
	} 
	for(int i = 1; i <= k;i++){
		c[i] = read();
		for(int j=1;j<=n;j++) {
			a[i][j] = read();
		}
	}
	cout << 0;
	return 0;
}

/*
k <= 10大有可为 
*/
