#include<bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T>
inline void read(T &x) {
	int f = 1;
	x = 0;
	char c = getchar();
	for ( ; !isdigit(c); c = getchar()) {
		if (c == '-') {
			f = -f;
		}
	}
	for ( ; isdigit(c); c = getchar()) {
		x = (x << 3) + (x << 1) + (c & 15);
	}
	x *= f;
}
template <typename T>
inline void write(T x) {
	if (x < 0) {
		x = -x;
		putchar ('-');
	}
	if (x > 9) {
		write(x / 10);
	}
	putchar ((x % 10) | 48);
}
const int M = 2e6 + 50, N = 1e4 + 50; 
int n, m, k, ans, fa[M], a[M];
struct node{
	int u, v, w;
}p[M];
bool cmp(node x, node y) {
	return x.w < y.w;
}
int find (int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int main () {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	read(n), read(m), read(k);
	for (int i = 1; i <= n; i ++) {
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		read(p[i].u), read(p[i].v), read(p[i].w);
	}
	for (int j = 1; j <= k; j ++) {
		int s;
		read(s);
		for (int i = 1; i <= n; i ++) {
			read(a[i]);
		}
	}
	sort(p + 1, p + 1 + m, cmp);
	for (int i = 1; i <= m; i ++) {
		int rootx = find(p[i].u), rooty = find(p[i].v);
		if (rootx != rooty) {
			fa[rooty] = rootx;
			ans += p[i].w;
		}
	}
	cout << ans;
	return 0;
}
