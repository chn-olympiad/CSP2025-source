#include <bits/stdc++.h>
using namespace std;
const long long N = 2000010;
const long long INF = LONG_LONG_MAX;
long long n, m, k;
struct Edge {
	long long to, nxt, w;
} e1[N << 1], e[N << 1];
long long head1[N], head[N], num1, num; 
void add1(long long u, long long v, long long w) {
	e1[++num1] = (Edge) {v, head1[u], w};
	head1[u] = num1;
}
void add(long long u, long long v, long long w) {
	e[++num] = (Edge) {v, head[u], w};
	head[u] = num;
}
long long c[20][10010];
long long dis[N];
bool vis[N];
long long Prime(long long n) {
	//puts("");
	//puts(""); 
	priority_queue<pair<long long, long long> > q;
	for (long long i = 1; i <= n + 10; i++)
		dis[i] = INF, vis[i] = false;
	dis[1] = 0;
	q.push({-dis[1], 1});
	long long ans = 0;
	while (!q.empty()) {
		long long u = q.top().second;
		q.pop(); 
		if (vis[u]) continue;
		//printf("%lld ", u);
		ans += dis[u];
		vis[u] = true;
		for (long long i = head[u]; i; i = e[i].nxt) {
			long long v = e[i].to;
//			printf("%lld ", v);
			if (!vis[v] && dis[v] > e[i].w) {
				dis[v] = e[i].w;
				q.push({-dis[v], v});
				//printf("aaa   %lld %d\n", v, (int)vis[v]);
			}
		}
	}
	//printf("%lld ", ans);
	return ans;
}
void print() {
	puts("aa");
	for (long long u = 1; u <= n; u++) {
		printf("%lld : ", u);
		for (int i = head[u]; i; i = e[i].nxt) {
			printf("%lld ", e[i].to);
		}
		puts("");
	}
	puts("aa");
}
long long init(long long s) {
	memcpy(head, head1, sizeof(head));
	memcpy(e, e1, sizeof(e1));
	//print();
	long long cnt = 0;
	for (long long i = 1; i <= k; i++) {
		if ((s >> (i - 1)) & 1) {
			cnt += c[i][0];
			for (long long j = 1; j <= n; j++) {
				add(i + n, j, c[i][j]);
				add(j, i + n, c[i][j]);
			}
		}
	}
	//print();
	return cnt;
} 
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	for (long long i = 1; i <= m; i++) {
		long long u, v, w;
		scanf("%lld%lld%lld", &u, &v, &w);
		add1(u, v, w);
		add1(v, u, w);
	}
	for (long long i = 1; i <= k; i++) 
		for (long long j = 0; j <= n; j++) 
			scanf("%lld", &c[i][j]);
	long long ans = INF;
	for (long long s = 0; s < (1 << k); s++) {
		long long k = init(s);
		ans = min(k + Prime(n + k + 1), ans); 
	}
	printf("%lld", ans);
	return 0;
}
