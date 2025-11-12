#include<bits/stdc++.h>
using namespace std;

template<typename T> void qr(T &x) {
	x = 0; char c = getchar(); int f = 1;
	for (; !isdigit(c); c = getchar()) if (c == '-') {
		f = -1;
	}
	for (; isdigit(c); c = getchar()) {
		x = x * 10 + (c - '0');
	}
	x *= f;
}

template<typename T> void qw(T x) {
	if (x < 0) {
		putchar('-');
	}
	if (x > 9) {
		qw(x / 10);
	}
	putchar(x % 10 + '0');
}

typedef long long LL;
const int N = 1e4 + 50;
const int M = 1e6 + 50;

struct node {
	int x, y;
	LL w;
} e[M];

int fa[N];
LL sum[N], V[15][N];
priority_queue<node> Q;

int siz[N];
int findfa(int x) {
	if (fa[x] == x) {
		return fa[x];
	}
	return fa[x] = findfa(fa[x]);
}

bool cmp(node na, node nb) {
	return na.w < nb.w;
}

bool operator<(node na, node nb) {
	return na.w > nb.w;
}

int main () {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m, K;
	qr(n); qr(m); qr(K);
	
	for (int i = 1; i <= n + K; i ++) {
		fa[i] = i;
		siz[i] = 1;
	}
	
	for (int i = 1; i <= m; i ++) {
		qr(e[i].x); qr(e[i].y); qr(e[i].w);
	}
	sort (e + 1, e + m + 1, cmp);
	
	int len = 0;
	LL mx = 0;
	for (int i = 1; i <= m; i ++) {
		int x = e[i].x, y = e[i].y; LL w = e[i].w;
		int tx = findfa(x), ty = findfa(y);
		if (tx != ty) {
			fa[tx] = ty;
			len ++;
			Q.push({x, y, w});
			mx = max(mx, w);
		}
	}
	
	for (int i = 1; i <= K; i ++) {
		cin >> sum[i + n];
		for (int j = 1; j <= n; j ++) {
			cin >> V[i][j];
			len ++;
			if (V[i][j] <= mx) {
				Q.push({i + n, j, V[i][j] + sum[i + n]});
			}
		}
	}
	
	for (int i = 1; i <= n + K; i ++) {
		fa[i] = i;
		siz[i] = 1;
	}
	
	LL ans = 0, res = 0;
	while(!Q.empty()) {
		node no = Q.top(); Q.pop();
		int tx = findfa(no.x), ty = findfa(no.y);
		
		if (tx > n && siz[tx] == 1) {
			for (int i = 1; i <= n; i ++) {
				Q.push({tx, i, V[tx - n][i]});
			}
		}
		if (tx != ty) {
			fa[tx] = ty;
			if (tx <= n) {
				res ++;
			}
			siz[ty] += siz[tx];
			ans += no.w;
		}
		if (res == n - 1) {
			break;
		}
	}
	cout << ans << "\n";
	
	return 0;
}
