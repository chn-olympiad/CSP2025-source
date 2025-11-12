#include <bits/stdc++.h>

#define i64 long long

#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define eb emplace_back

using namespace std;

inline int Read() {int res; return scanf("%d", &res), res; }
inline i64 Read64() {i64 res; return scanf("%lld", &res), res; }

const int N = 100000 + 5;

int n, a[N][4], id[N], c[4];

void Solve() {
	n = Read();
	c[1] = c[2] = c[3] = 0;
	int ans = 0;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= 3; ++ j) a[i][j] = Read();
		id[i] = 0;
		for(int j = 1; j <= 3; ++ j) {
			if(!id[i] || a[i][id[i]] < a[i][j]) id[i] = j;
		}
		c[id[i]] ++, ans += a[i][id[i]];
	}
	if(max(max(c[1], c[2]), c[3]) <= n / 2) return printf("%d\n", ans), void();
	int x = 0, y = 0;
	if(c[1] > n / 2) x = 1;
	if(c[2] > n / 2) x = 2;
	if(c[3] > n / 2) x = 3;
	y = c[x] - n / 2; 
	
	vector<int> G;
	for(int i = 1; i <= n; ++ i) {
		if(id[i] == x) {
			int maxx = 0;
			if(x != 1) maxx = max(maxx, a[i][1]);
			if(x != 2) maxx = max(maxx, a[i][2]);
			if(x != 3) maxx = max(maxx, a[i][3]);
			G.eb(a[i][x] - maxx);
		}
	}
	
	sort(G.begin(), G.end());
	for(int i = 0; i < y; ++ i) ans -= G[i];
	printf("%d\n", ans);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T = Read();
	while(T --) Solve(); 
	return 0;
}
/*
六王毕，四海一，蜀山兀，阿房出。覆压三百余里，隔离天日。骊山北构而西折，直走咸阳。二川溶溶，流入宫墙。五步一楼，十步一阁。廊腰缦回，檐牙高啄，各抱地势，勾心斗角。盘盘焉，囷囷焉，蜂房水涡，矗不知其几千万落。
后面忘了（悲） 
*/
