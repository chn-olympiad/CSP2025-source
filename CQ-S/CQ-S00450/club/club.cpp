#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int a[MAXN][3]; int sel[MAXN];

char buf[1 << 25], *S, *T;
char gc() {return S == T && (T = (S = buf) + fread(buf, 1, 1 << 25, stdin)) == buf ? 0 : *S++;}
int read() {
	char ch; while ((ch = gc()) <= ' '); int x = ch - '0';
	while ((ch = gc()) > ' ') x = 10 * x + ch - '0'; return x;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t = read(); while (t--) {
		int n = read();
		for (int i = 1; i <= n; i++) a[i][0] = read(), a[i][1] = read(), a[i][2] = read();
		int cnt[3] = {0, 0, 0};
		long long ans = 0; for (int i = 1; i <= n; i++) {
			sel[i] = 0; for (int j = 1; j < 3; j++) {
				if (a[i][j] > a[i][sel[i]]) sel[i] = j;
			}
			ans = (ans + a[i][sel[i]]); cnt[sel[i]]++;
		}
		int f = -1; for (int i = 0; i < 3; i++) if (2 * cnt[i] > n) f = i;
		if (f == -1) printf("%lld\n", ans);
		else {
			vector<int> vc;
			for (int i = 1; i <= n; i++) {
				if (sel[i] == f) {
					int dif = 0x3f3f3f3f;
					for (int j = 0; j < 3; j++) if (j != sel[i]) {
						dif = min(dif, a[i][f] - a[i][j]);
					}
					vc.push_back(dif);
				}
			}
			sort(vc.begin(), vc.end());
			for (int _ = 0; _ < cnt[f] - n / 2; _++) ans -= vc[_];
			printf("%lld\n", ans);
		}
	}
}
/*
run club < club1.in > club1.out
run club < club2.in > club2.out
run club < club3.in > club3.out
run club < club4.in > club4.out
run club < club5.in > club5.out
diff club1.out club1.ans -Z
diff club2.out club2.ans -Z
diff club3.out club3.ans -Z
diff club4.out club4.ans -Z
diff club5.out club5.ans -Z
*/
/*
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int a[MAXN];
int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	int cb = 1, ans = 1; for (int i = 2; i <= n; i++) {
		if (a[i] == a[i - 1]) ans = max(ans, ++cb);
		else cb = 1;
	} printf("%d\n", ans);
}
*/