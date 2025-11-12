#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e4 + 17, M = 2e6+7;
int i, j, k, n, m, l;
int a[17][N], c[N],f[N];

struct eg {
	int a, b, c;
} d[M], e[M];

int find(int x) {
	if(x == f[x]) return x;
	return f[x] = find(f[x]);
}

bool cmp(eg a, eg b) {
	return a.c < b.c;
}

ll ks() {
	int i;
//	puts("qwq");
//	cout << l << "\n";
	for(i=1; i<=l; i++) e[i] = d[i];
	sort(e+1, e+1+l, cmp);
	for(i=1; i<=n+k; i++) f[i] = i;
	ll cnt = 0;
	for(i=1; i<=l; i++) {
		int a = e[i].a, b = e[i].b;
//		cout << a << " " << b << "\n";
		if(find(a) != find(b)) {
			f[find(a)] = find(b);
			cnt += e[i].c;
		}
	}
//	cout << cnt << "\n";
	return cnt;
}
ll ans = 1e17;
void dfs(int s, ll w) {
//	cout << s << " " << w << "\n";
	if(w >= ans) return;
	if(s > k) {
		ans = min(ans, ks() + w);
		return;
	}
	dfs(s+1, w);
	int tmp = l;
	for(int i=1; i<=n; i++) d[++l] = {n+s, i, a[s][i]};
	dfs(s+1, w+c[s]);
	l = tmp;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(i=1; i<=m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		d[i] = (eg){a, b, c};
	}
	l = m;
	for(i=1; i<=k; i++) {
		scanf("%d", &c[i]);
		for(j=1; j<=n; j++) scanf("%d", &a[i][j]);
	}
	dfs(1, 0);
	printf("%lld\n", ans);
	return 0;
}
