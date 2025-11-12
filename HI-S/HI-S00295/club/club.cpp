#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int t, n, a[N][5];
int tr[N];
struct Node {
	int a, b;
	bool operator < (const Node& z)const {
		return b-a > z.b-z.a;
	}
} e[N];
int vis[N];
struct Dot {
	int val, id, dir;
	bool operator < (const Dot& z)const {
		if (val == z.val) {
			int oth = (dir == 1 ? 2 : 1);
			int othz = (z.dir == 1 ? 2 : 1);
			return a[id][oth] < a[z.id][othz];
		} else return val < z.val;
	}
};
priority_queue<Dot> q;
priority_queue<int, vector<int>, greater<int> > q1;
int f[210][210][210], b[N], sa[N], sb[N];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		scanf("%d", &n);
		if (n <= 200) {
			int ans = 0;
			memset(f, -0x3f, sizeof f);
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= 3; j++) {
					scanf("%d", &a[i][j]);
				}
				ans += a[i][1];
				f[0][0][0] = 0;
				for (int j = 0; j <= i; j++) {
					for (int k = 0; k <= i; k++) {
						f[i][j][k] = f[i-1][j][k];
						if (j) f[i][j][k] = max(f[i][j][k], f[i-1][j-1][k] + a[i][2]-a[i][1]);
						if (k) f[i][j][k] = max(f[i][j][k], f[i-1][j][k-1] + a[i][3]-a[i][1]);
					}
				}
			}
			int h = n / 2, tmp = -2147483647;
			for (int i = 0; i <= n; i++) {
				for (int j = 0; j <= n; j++) {
					if (i <= h && j <= h && i + j >= h) {
						tmp = max(tmp, f[n][i][j]);
					}
				}
			}
			printf("%d\n", ans + tmp);
		} else {
			bool A = true, B = true;
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= 3; j++) {
					scanf("%d", &a[i][j]);
				}
				if (!(a[i][2] == a[i][3] && a[i][3] == 0)) {
					A = false;
				}
				if (!(a[i][3] == 0)) {
					B = false;
				}
				ans += a[i][1];
			}
			if (A) {
				for (int i = 1; i <= n; i++) {
					b[i] = a[i][1];
				}
				sort(b+1, b+n+1);
				int ans = 0, h = n / 2, sum = 0;
				for (int i = n; i > h; i--) {
					sum += b[i];
					ans = max(ans, sum);
				}
				printf("%d\n", ans);
			} else if (B) {
				int sum = 0, h = n / 2;
				for (int i = 1; i <= n; i++) {
					e[i].a = a[i][1];
					e[i].b = a[i][2];
				}
				sort(e+1, e+n+1);
				for (int i = 1; i <= n; i++) {
					if (i <= h) sum += e[i].b;
					else sum += e[i].a;
				}
				printf("%d\n", sum);
			} else {
				while (q.size()) q.pop();
				for (int i = 1; i <= n; i++) {
					vis[i] = 0;
					q.push((Dot){a[i][2]-a[i][1], i, 1}); 
					q.push((Dot){a[i][3]-a[i][1], i, 2});
				}
				int sb = 0, sc = 0, sum = 0, tmp = -2147483647, h = n / 2;
				while (q.size()) {
					Dot t = q.top(); q.pop();
					int dir = t.dir, val = t.val, id = t.id;
					if (vis[id]) continue;
					if (dir == 1) sb++;
					else sc++;
					if (sb > h) {
						sb = h;
						continue;
					}
					if (sc > h) {
						sc = h;
						continue;
					}
					vis[id] = 1;
					sum += val;
					if (sb + sc >= h) {
						tmp = max(tmp, sum);
					}
				}
				printf("%d\n", ans + tmp);
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
