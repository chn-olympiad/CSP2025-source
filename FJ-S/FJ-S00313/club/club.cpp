// Author Johen_ovo wuzeen
#include <bits/stdc++.h>
using namespace std;
#define prt printf
#define pb push_back
#define _x first 
#define _y second

typedef long long ll;
typedef pair<int,int> PII;
typedef unsigned long long ull;
const int N = 1e5 + 7, INF = 0x3f3f3f3f;

void put(ll x, char el = '\n') {
	printf("%lld", x);
	putchar(el);
}

int a[N][4];
vector<PII> c[4];

void solve() {
//	puts("---new---");
	
	memset(a, 0, sizeof a);
	c[1].clear(); c[2].clear(); c[3].clear();
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
		int x = a[i][1], y = a[i][2], z = a[i][3];
		vector<PII> tmp = {{x, 1}, {y, 2}, {z, 3}};
		sort(tmp.begin(), tmp.end(), greater<PII>());
		c[tmp[0]._y].pb({tmp[0]._x, i});
	}
	
//	puts("before");
//	for (int i = 1; i <= 3; i++) {
//		sort(c[i].begin(), c[i].end());
//		put(i);
//		for (auto j : c[i]) {
//			prt("%d %d\n", j._x, j._y);
//		}
//		puts("-----");
//	}
	
	
	for (int gp = 1; gp <= 3; gp++) {
		for (int _ = c[gp].size(); _ > n / 2; _--) {
			int loss = INF, who = 0, to = 0;
			for (int i = 0; i < c[gp].size(); i++) {
				int val = c[gp][i]._x, idx = c[gp][i]._y;
				if (idx == -1) continue;
				for (int j = 1; j <= 3; j++) {
					if (j == gp) continue;
					int nval = a[idx][j];
					if (val - nval < loss) {
						loss = val - nval;
						who = i;
						to = j;
					}
				}
			}
//			put(who);
			
			c[to].pb({a[c[gp][who]._y][to], c[gp][who]._y});		
			c[gp][who] = {0, -1};
		}
	}
	
//	puts("after");
//	for (int i = 1; i <= 3; i++) {
//		sort(c[i].begin(), c[i].end());
//		put(i);
//		for (auto j : c[i]) {
//			prt("%d %d\n", j._x, j._y);
//		}
//		puts("-----");
//	}
	
	int ans = 0;
	for (int i = 1; i <= 3; i++) {
		for (auto j : c[i]) {
			ans += j._x;
		}
	}
	put(ans);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
