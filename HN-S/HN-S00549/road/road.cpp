#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 2e6 + 1, MAXK = 1e4 + 10;

int n, m, k, len, ans = 1e18, c[MAXK], d[11][MAXK], f[MAXN];
struct edge {
	int x, y, z;
}a[MAXN], b[MAXN];
bool cmp(edge a, edge b) {
	return a.z < b.z;
}
vector<int> addn;
int Find(int x) {
	return (f[x] == x ? x : f[x] = Find(f[x]));
}
void check() {
	int res = 0;
	iota(f + 1, f + n + k + 1000, 1);
	sort(b + 1, b + len + 1, cmp);
	int dotsum = n + k;
	int cho = 0;
	for(int i = 1; i <= len; i++) {
		int x = b[i].x, y = b[i].y, z = b[i].z;
		if(Find(x) != Find(y)) {
			int fx = Find(x), fy = Find(y);
			f[fx] = fy;
			res += z;
			cho++;
			if(cho == dotsum - 1) {
				break;
			}
		}
	}
	ans = min(ans, res);
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		cin >> a[i].x >> a[i].y >> a[i].z;
	}
	bool q = true;
	for(int i = 1; i <= k; i++) {
		cin >> c[i];
		q &= (c[i] == 0);
		bool res = false;
		for(int j = 1; j <= n; j++) {
			cin >> d[i][j];
			res |= (d[i][j] == 0);
		}
		q &= res;
	}
	if(q || k == 0) {
		for(int i = 1; i <= m; i++) {
			b[++len] = a[i];
		}
		for(int i = 1; i <= k; i++) {
			for(int j = 1; j <= n; j++) {
				b[++len] = {i + n, j, d[i][j]};
			}
		}
		check();
		cout << ans;
	}
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

5 4 1
1 2 10
2 3 10
3 4 10
4 5 10
1000 0 0 0 0 0
*/
