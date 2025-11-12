#include<bits/stdc++.h>
#define endl '\n'
#define pi pair<int, int>
#define ll long long

using namespace std;
const int N = 1e4 + 10 + 10, M = 2e6 + 10;
int n, m, k, b[N], a[20][N], len, fa[N];
ll ans = 1e18;

struct longyue{
	int u, v, w;
	bool operator <(const longyue &other) const{
		return w > other.w;
	}
}ve[M];
priority_queue<longyue> q;

inline void init(){
	for (int i = 1; i <= len; i++)
		fa[i] = i;
	return ;
}

int find(int x) {
	return ((fa[x] ^ x) ? (fa[x] = find(fa[x])) : x);
}

inline void merge(int u, int v) {
	int fu = find(u), fv = find(v);
	fa[fu] = fv;
	return ;
}

inline int read(){
	int tt = 0, ff = 1;
	char c = getchar();
	while(c < '0' || '9' < c) {
		if (c == '-') ff = -1;
		c = getchar();
	}
	while ('0' <= c && c <= '9') tt = (tt << 3) + (tt << 1) + c - '0', c = getchar();
	return tt * ff;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
//	cin.tie(nullptr)->sync_with_stdio(false);
//	scanf("%d %d %d", &n, &m, &k);
//	cin >> n >> m >> k;
	n = read(), m = read(), k = read();
	for (int i = 1, u, v, w; i <= m; i++) {
//		scanf("%d %d %d", &u, &v, &w);
//		cin >> u >> v >> w;
//		vec.push_back({u, v, w});
		ve[i]={read(), read(), read()};
	}
	for (int i = 1; i <= k; i++) {
//		scanf("%d", &b[i]);
//		cin >> b[i];
		b[i] = read();
		for (int j = 1; j <= n; j++)
			a[i][j] = read();
//			cin >> a[i][j];
//			scanf("%d", &a[i][j]);
	}
//	return 0;
	int bits = (1 << k);
	for (int i = 0; i < bits; i++) {
		printf("%d\n", i);
		ll sum = 0;
		len = n;
		for (int j = 1; j <= k; j++) {
			if ((i | (1 << j)) ^ i) continue;
			sum += b[j];
			len++;
			for (int l = 1; l <= n; l++)
				q.push({len, l, a[j][l]});
		}
		init();
		int count = len - 1;
		for (int i = 1; i <= m; i++)
			q.push(ve[i]);
		while (q.size() && count) {
			auto head = q.top();
			q.pop();
			int u = head.u, v = head.v;
			if (find(u) == find(v)) continue;
			merge(u, v);
			sum += head.w;
			count--;
		}
		ans = min(ans, sum);
		while (q.size()) q.pop(); // clean
	}
//	cout << ans << endl;
	printf("%lld\n", ans);
	return 0;
}

