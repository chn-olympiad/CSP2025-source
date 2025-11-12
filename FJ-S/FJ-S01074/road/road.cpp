#include <bits/stdc++.h>
#define sp " "
#define el "\n"
#define r0 return 0
#define F(i, a, b, c) for (int i = a; i <= b; i += c)
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef string str;

int n, m, k;
int f[1100000];
int c[20];
int a[20][11000];

struct Info {
	int x, y, w;
} b[1100000];

inline int find(int x) {
	if (x == f[x]) {
		return x;
	}
	return f[x] = find(f[x]);
}

inline bool cmp(Info x, Info y) {
	return x.w < y.w;
}

signed main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	//freopen("road.in", "r", stdin);
	//freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	F(i, 1, m, 1) {
		cin >> b[i].x >> b[i].y >> b[i].w;
	}
	F(i, 1, k, 1) {
		cin >> c[i];
		F(j, 1, n, 1) {
			cin >> a[i][j];
		}
	}
	std::sort(b + 1, b + m + 1, cmp);
	iota(f + 1, f + n + 1, 1LL);
	int ans = 0;
	F(i, 1, m, 1) {
		int fx = find(b[i].x), fy = find(b[i].y);
		if (fx != fy) {
			f[fx] = fy;
			ans += b[i].w;
		}
	}
	cout << ans << el;
	r0;
}
