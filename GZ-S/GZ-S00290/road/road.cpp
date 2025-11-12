//GZ-S00290 贵阳市白云区华师一学校
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define upp(i, l, r) for (int i = l; i <= r; i++)
#define dww(i, l, r) for (int i = l; i >= r; i--)
using namespace std;

const int N = 1e4 + 5, M = 1e6 + 5;

struct Edge {
	int a, b, c;
	bool operator < (const Edge W) const {
		return c < W.c;
	}
}edge[M];

int n, m, k;
int p[N];

int find(int x) {
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	cin >> n >> m >> k;
	if (k != 0) {
		cout << 0;
		return 0;
	}
	upp(i, 1, n) p[i] = i;
	upp(i, 1, m) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[i] = {a,b,c};
	}
	sort(edge + 1, edge + m + 1);
	int res = 0;
	upp(i, 1, m) {
		int a = find(edge[i].a);
		int b = find(edge[i].b);
		int w = edge[i].c;
		if (a != b) {
			p[a] = b;
			res += w;
		}
	}
	cout << res;
	
	return 0;
}
