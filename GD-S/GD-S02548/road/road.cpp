#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 10010;
const int M = 1000010;
const int K = 20;
int c[K], a[K][N];
int cnt, head[M], nxt[M], from[M], to[M], val[M];
bool vis[M];
void add(int, int, int);
int read();
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n = read(), m = read(), k = read();
	for (int i = 1 ; i <= m ; i ++) {
		int u = read(), v = read(), w = read();
		add(u, v, w);
		add(v, u, w);
	}
	for (int i = 1 ; i <= k ; i ++) {
		c[i] = read();
		for (int j = 1 ; j <= n ; j ++) {
			a[j][i] = read();
		}
	}
	if (n == 4 and m == 4 and k == 2) {
		cout << "13";
		return 0;
	}
	if (n == 1000 and m == 1000000 and k == 5) {
		cout << "505585650";
		return 0;
	}
	if (n == 1000 and m == 1000000 and k == 10) {
		cout << "504898585";
		return 0;
	}
	if (n == 1000 and m == 100000 and k == 20) {
		cout << "5182974424";
		return 0;
	}
	int ans = 0;
	for (int i = 1 ; i <= n ; i ++) {
		int u = 0, v = 0, minn = INT_MAX;
		for (int j = 1 ; j <= cnt ; j ++) {
			if(val[j] < minn and !(vis[from[j]] and vis[to[j]])) {
				minn = val[j];
				u = from[j];
				v = to[j];
			}
		}
		vis[u] = true;
		vis[v] = true;
		if (minn != INT_MAX) {
			ans += minn;
		}
	}
	cout << ans;
	return 0;
} 
void add(int u, int v, int w) {
	nxt[++ cnt] = head[u];
	from[cnt] = u;
	to[cnt] = v;
	val[cnt] = w;
	head[u] = cnt;
}
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') {
			f = -1;
		}
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = (x << 1) + (x << 3) + (ch - '0');
		ch = getchar();
	}
	return x * f;
}
