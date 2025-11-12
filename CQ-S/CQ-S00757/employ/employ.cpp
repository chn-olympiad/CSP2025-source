#include <bits/stdc++.h>

using namespace std;

int n, m, a[510], b[510], c[510];
long long ans;
bool d[510];
char s[510];

inline void solve (int l) {
	if (l == n + 1) {
		int cnt = 0, num = 0;
		for (int i = 1; i <= n; i++) {
			//printf ("%d ", c[i]);
			if (a[i] == 0) {
				cnt++;
				continue;
			}
			//printf (" %d %d  ", cnt, b[c[i]]);
			if (cnt >= b[c[i]]) {
				cnt++;
				continue;
			}
			cnt = 0;
			num++;
		}
		//printf ("\n");
		if (num >= m) {
			ans++;
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!d[i]) {
			d[i] = true;
			c[l] = i;
			solve (l + 1);
			d[i] = false;
		}
	}
}

int main () {
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (int i = 0; i <= n; i++) {
		scanf ("%c", &s[i]);
		a[i] = s[i] - '0';
	}
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &b[i]);
	}
	solve (1);
	printf ("%d", ans);
}
