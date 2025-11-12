#include <bits/stdc++.h>
 
using namespace std;
using cint = const int;
using LL = long long;
using cLL = const long long;

#define N 100005
#define base 127
#define mod 998244353
#define inf 1000000007

const double eps = 1e-9;
const double PI = acos(-1.0);

int a[N][5], mx[N][5];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int n; t--; ) {
		cin >> n;
		vector<int> vt[5];
		LL ans = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			mx[i][1] = 1;
			mx[i][2] = 2;
			mx[i][3] = 3;
			sort(mx[i] + 1, mx[i] + 3 + 1, [&](cint x, cint y) {
				return a[i][x] > a[i][y];
			});
			vt[mx[i][1]].emplace_back(i);
			ans += a[i][mx[i][1]];
		}
		int p = -1;
		for (int i = 1; i <= 3 && p == -1; ++i)
			if ((int)vt[i].size() > n / 2)
				p = i;
		if (p != -1) {
			sort(vt[p].begin(), vt[p].end(), [](cint x, cint y) {
				return a[x][mx[x][1]] - a[x][mx[x][2]] > a[y][mx[y][1]] - a[y][mx[y][2]];
			});
			for (int i = n / 2, sz = vt[p].size(); i < sz; ++i)
				ans -= a[vt[p][i]][mx[vt[p][i]][1]] - a[vt[p][i]][mx[vt[p][i]][2]];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
