#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int MAXN = 20;
int n, m, R, a[MAXN * MAXN], cur[MAXN * MAXN], cnt, h = 1, w;
void getnxt(int &a, int &b) {
	if (a & 1) {
		b++;
		if (b > n) a++, b = n;
	} else {
		b--;
		if (b < 1) a++, b = 1;
	}
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &R);
	for(int i = 1; i < n * m; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n * m, greater<int>());
	for(int i = 1; i < n * m; i++) {
		if (a[i] < R) cur[++cnt] = R;
		else cur[++cnt] = a[i];
	}
	for(int i = 1; i <= cnt; i++) {
		getnxt(h, w);
		if (cur[i] == R) {
			printf("%d %d", h, w);
			return 0;
		}
	}
	if (n & 1) printf("%d %d", n, n);
	else printf("%d %d\n", n, 1);
	return 0;
}
