#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;
typedef pair<int, long long> pii;

const int N = 1e4 + 10 + 10;
const int M = 1e6 + 10;
const int inf = 2e9;

//struct node
//	int to, w;
//	bool operator < (const node &aa) const {
//		return w < aa.w;
//	}
//} ap[M];

int aln, n, m, k;
ll ans;
vector<pii> vc[N];
bool vis[N];
ll dis[N];

void bfs() {
	memset(dis, 0x7f, sizeof(dis));
	
	int mi;
	dis[0] = inf;
	if (k == 0) {
		dis[1] = 0;
	} else {
		for (int i = 1; i <= k; i++) dis[n+i] = 0;
	}
	
	for (int jk = 1; jk <= aln; jk++) {
		mi = 0;
		for (int i = 1; i <= aln; i++) {
			if (!vis[i] && dis[i] < dis[mi]) mi = i;
		}
		ans += dis[mi];
		vis[mi] = true;
//		printf("upd %d : %lld %lld\n", mi, dis[mi], ans);
		for (pii t:vc[mi]) {
			if (!vis[t.first]) {
				dis[t.first] = min(dis[t.first], t.second);
			}
		}
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	int u, v;
	ll w, g;
	
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %lld", &u, &v, &w);
		vc[u].push_back(make_pair(v, w));
		vc[v].push_back(make_pair(u, w));
	}
	for (int i = 1; i <= k; i++) {
		scanf("%lld", &g);
		for (int j = 1; j <= n; j++) {
			scanf("%lld", &g);
			vc[n+i].push_back(make_pair(j, g));
		}
	}
	aln = n + k;
	bfs();
	printf("%lld", ans);
	return 0;
}
/*
4 4 2
1 2 2
1 3 1
3 4 3
2 3 5
0 2 5 0 4
0 4 0 2 3

9 8 2
1 2 2
1 3 3
3 5 3
3 4 2
4 6 2
6 7 3
7 9 2
7 8 3
0 114514 0 114514 114514 114514 114514 114514 114514 114514
0 114514 114514 114514 114514 114514 114514 114514 114514 0
*/

