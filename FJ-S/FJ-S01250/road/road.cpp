#include <iostream>
#include <cstdio>
#include <algorithm>
//#include <queue>
#define ull unsigned long long
using namespace std;
int n, m, k, f[11005], c[105], cnt;
ull ans, minn;
bool fo[105];
struct edge {
	int u, v, w;
}a[5000006];
bool cmp(edge aa, edge b) {return aa.w < b.w;}
int find(int x) {return (x == f[x])? x : f[x] = find(f[x]);}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &a[i].u, &a[i].v, &a[i].w);
	}
	cnt = m;
	for (int i = 1; i <= k; i++) {
		scanf("%d", &c[i]);
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[++cnt].w);
			a[cnt].u = n + i; a[cnt].v = j;
		}
	}
	sort(a + 1, a + m + 1, cmp);
//	sort(a + m + 2, a + cnt + 1, cmp);
	for (int i = 1; i <= n + k; i++) f[i] = i;
	for (int i = 1; i <= m; i++) {
		int r1 = find(a[i].u), r2 = find(a[i].v);
		if (r1 != r2) {
			ans += a[i].w;
			f[r2] = r1;
		}
	}
	minn = ans;
	sort(a + 1, a + cnt + 1, cmp);
	for (int I = 1; I <= k; I++) {
		fo[I] = 1;
		ans = 0;
		for (int i = 1; i <= k; i++) ans += c[i] * fo[i];
		for (int i = 1; i <= n + k; i++) f[i] = i;
		for (int i = 1; i <= cnt; i++) {
			if (a[i].u > n && !fo[a[i].u - n]) continue;
			int r1 = find(a[i].u), r2 = find(a[i].v);
			if (r1 != r2) {
				ans += a[i].w;
				f[r2] = r1;
			}
		}
		if (ans > minn) fo[I] = 0;
		else minn = ans;
	}
	printf("%lld", minn);
//	fclose(stdin); fclose(stdout);	
	return 0;
}
