#include<bits/stdc++.h>
using namespace std;

const int MAXV = 10005;
const int MAXE = 1200005;
const int MAXK = 15;

struct EDGE {
	int from, to, w;
};

int n, m, k;
long long ans = 1e18;
int cnt_n, cnt_m;
int c[MAXK];
int rot[MAXV];
bool can[MAXK];
EDGE e[MAXE];

int READ() {
	int res = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') {
		res = res * 10 + ch - 48;
		ch = getchar();
	}
	return res;
}

void INIT() {
	for (int i = 1; i <= cnt_n; ++i) rot[i] = i;
}

int FIND(int x) {
	if (x == rot[x]) return x;
	return rot[x] = FIND(rot[x]);
}

bool COMP(EDGE x, EDGE y) {
	return x.w < y.w;
}

long long KRUSKAL(int x) {
	INIT();
	int num = 0;
	long long sum = 0;
	for (int i = 1; i <= cnt_m; ++i) {
		if (e[i].from > n && !can[ e[i].from - n] ) continue;
		if (e[i].to > n && !can[ e[i].to - n ]) continue;
		
		int fx = FIND(e[i].from), fy = FIND(e[i].to);
		if (fx == fy) continue;
		
		rot[fx] = fy;
		sum += e[i].w;
		++num;
		if (num == x - 1) return sum;
	}
	return sum;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		e[++cnt_m].from = READ();
		e[cnt_m].to = READ();
		e[cnt_m].w = READ();
	}
		
	cnt_n = n;
	for (int i = 1; i <= k; ++i) {
		++cnt_n;
		c[i] = READ();
		for (int j = 1; j <= n; ++j) e[++cnt_m] = (EDGE) {cnt_n, j, READ()};
	}
	sort(e + 1, e + cnt_m + 1, COMP);
	for (int i = 0; i < (1 << k); ++i) {
		int cnt = 0;
		long long sum = 0;
		memset(can, 0, sizeof(can));
		for (int j = 0; j < k; ++j) {
			if ( ( (i >> j) & 1 ) == 0 ) continue;
			++cnt;
			sum += c[j + 1];
			can[j + 1] = 1;
		}
		ans = min(ans, sum + KRUSKAL(cnt + n));
	}
	cout << ans << endl;
}
