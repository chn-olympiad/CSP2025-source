#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 5, M = 2e6 + 5;
const long long INF = 1e18;

int n, m, k, tot, b[15], fa[N], c[15];

struct E {
	int x, y, w;
} e[M], a[M], v[M], cnt[M];
  
bool cmp(E X, E Y) {
	return X.w < Y.w;
}

struct S {
	int x, w;
} s[15][N];

bool CMP(S X, S Y) {
	return X.w < Y.w;
}

int find(int x) {
	return (x == fa[x] ? x : fa[x] = find(fa[x]));
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;	
    for (int i = 1, x, y, w; i <= m; i++) {
    	cin >> x >> y >> w;
		e[i] = {x, y, w}; 
	}
	sort(e + 1, e + 1 + m, cmp);
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	long long ans = INF;
	for (int i = 1; i <= m; i++) {
		int x = e[i].x, y = e[i].y;
		int cnt = find(x), tmp = find(y);
		if (cnt != tmp) {
			fa[cnt] = tmp;
			a[++tot] = e[i];
		}
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1, x; j <= n; j++) {
			cin >> x;
			s[i][j] = {j, x};
		}
		sort (s[i] + 1, s[i] + 1 + n, CMP);
	}
	for (int dis = 0; dis < (1 << k); dis++) {
		for (int i = 1; i <= n + k; i++) {
			fa[i] = i;
		}
		int h = 0;
		int len = tot;
		long long sum = 0;
		for (int i = 1; i <= len; i++) {
			v[i] = a[i];
		}
		for (int i = 1; i <= k; i++) {
			if ((dis >> (i - 1)) & 1) {
				b[++h] = i;
				sum += c[i];
			}
		}
		for (int i = 1; i <= h; i++) {
			int x = b[i], d = n + i;
			int hone = 1, htwo = 1;
			int r = 0;
			for (; hone <= len && htwo <= n;) {
				if (v[hone].w <= s[x][htwo].w) {
					cnt[++r] = {v[hone].x, v[hone].y, v[hone].w};
					hone++;
				} else {
					cnt[++r] = {d, s[x][htwo].x, s[x][htwo].w};
					htwo++;
				}
			}
			for (; hone <= len; hone++) {
				cnt[++r] = {v[hone].x, v[hone].y, v[hone].w};
			}
			for (; htwo <= n; htwo++) {
				cnt[++r] = {d, s[x][htwo].x, s[x][htwo].w};
			}
			len = r;
			for (int j = 1; j <= len; j++) {
				v[j] = cnt[j];
			} 
		}
		int o = n + h - 1;
		for (int i = 1; i <= len && o; i++) {
			int x = v[i].x, y = v[i].y;
			int ak = find(x), bs = find(y);
			if (ak != bs) {
				o--;
				sum += (long long)v[i].w;
				fa[ak] = bs;
			}
		}
		ans = min(ans, sum);
	}
	cout << ans;
	return 0;
}
