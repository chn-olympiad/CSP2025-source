#include <bits/stdc++.h>
using namespace std;
const int SZ = 1 << 20;
char buf[SZ], *p1(buf), *p2(buf);
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, SZ, stdin), p1 == p2)) ? EOF : *p1++
int read() {
	int x = 0;
	char c = gc();
	while (c < '0' || c > '9')
		c = gc();
	while (c >= '0' && c <= '9')
		x = x * 10 + (c & 15), c = gc();
	return x;
}
typedef long long ll;
int n, m, k, cnt;
int fa[20005];
ll c[20];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
struct M {
	int x, y;
	ll z;
} a[1000005], b[200005];
inline bool cmp(M x, M y) { return x.z < y.z; }
ll ans = 0;
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (int i = 1; i <= m; i++)
		a[i] = (M){read(), read(), read()};
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	sort(a + 1, a + m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		if (find(a[i].x) == find(a[i].y))
			continue;
		fa[find(a[i].x)] = find(a[i].y);
		b[++cnt] = a[i];
		ans += a[i].z;
	}
	for (int i = 1; i <= k; i++) {
		c[i] = read();
		for (int j = 1; j <= n; j++)
			b[++cnt] = (M){j, i + n, read()};
	}
	sort(b + 1, b + cnt + 1, cmp);
	for (int i = 1; i < (1 << k); i++) {
		for (int j = 1; j <= n + k; j++)
			fa[j] = j;
		ll res = 0;
		for (int j = 0; j < k; j++) {
			if (i & (1 << j))
				res += c[j + 1];
		}
		for (int j = 1; j <= cnt; j++) {
			if (b[j].y > n && (i & (1 << (b[j].y - n - 1))) == 0) 
				continue;
			if (find(b[j].x) == find(b[j].y))
				continue;
			fa[find(b[j].x)] = find(b[j].y);
			res += b[j].z;
		}
		ans = min(ans, res);
	}
	cout << ans << '\n'; 
	return 0;
} 
