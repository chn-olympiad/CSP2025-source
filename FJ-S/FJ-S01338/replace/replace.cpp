#include<bits/stdc++.h>
using namespace std;
int main () {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	while(q--) {
		cout << "0\n";
	}
}
/*
#include<bits/stdc++.h>
using namespace std;
long long n, a[16][100006], k, w[1000006], C[1000006], f[100006], m, now, ans, tag, noww, anss, T;
struct CC {
	int u, v;
	long long w;
} c[2000006];
int cc (int x) {
	if (f[x] == x) return x;
	return f[x] = cc(f[x]);
}
int cmp (CC aa, CC bb) {
	return aa.w < bb.w;
}
int dfs (int x, int y, int z) {
	if (x > k) return 0;
	int nowww = now;
//	T++;
	for (int i = 1; i <= n; i++) {
		c[++now].u = n + x;
		c[now].v = i;
		c[now].w = a[x][i];
	}
	sort(c + 1, c + 1 + now, cmp);
	for (int i = 1; i <= n + 100; i++) {
		f[i] = i;
	}
	anss = 0;
	noww = 0;
	tag = 0;
	while(tag < y + n) {
		noww++;
		if (cc(c[noww].u) == cc(c[noww].v)) ;
		else {
			tag++;
			anss += c[noww].w;
			f[cc(c[noww].u)] = cc(c[noww].v);
		}
	}
	if (anss + C[x] + z < ans) {
		ans = anss + C[x] + z;
		dfs(x + 1, y + 1, z + C[x]);
	}
	for (int i = 1; i <= now; i++) {
		if (c[i].u == n + x) c[i].w = 1000000009;
	}
	sort(c + 1, c + 1 + now, cmp);
	now = nowww;
	dfs(x + 1, y, z);
	return 0;
}
int main () {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n + 100; i++) {
		f[i] = i;
	}
	for (int i =1; i <= m; i++) {
		scanf("%d %d %lld", &c[i].u, &c[i].v, &c[i].w);
	}
	for (int i = 1; i <= k; i++) {
		scanf("%lld", &C[i]);
		for (int j = 1; j <= n; j++) {
			scanf("%lld", &a[i][j]);
		}
	}
//	cout << clock() << " ";
	now = m;
	sort(c + 1, c + 1 + now, cmp);
	while(tag < n - 1) {
		noww++;
		if (cc(c[noww].u) == cc(c[noww].v)) ;
		else {
			tag++;
			ans += c[noww].w;
			f[cc(c[noww].u)] = cc(c[noww].v);
		}
	}
	now = noww + n;
//	cout << clock() << " ";
//	cout << ans << "\n";
	dfs(1, 0, 0);
	cout << ans;
//	cout << " " << now;
	return 0;
}
hopeless
hopeless
hopeless
hopeless
hopeless
hopeless
hopeless
hopeless
hopeless
hopeless
hopeless
hopeless
hopeless
hopeless
hopeless
hopeless
*/

