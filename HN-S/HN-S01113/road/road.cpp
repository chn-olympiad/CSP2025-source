#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 1e4 + 5;
const int K = 15;
const int M = 3e6 + 5;
int n, m, k, b[K], c[K][N], fa[N], cnt, ans, sum, p;
struct Node{
	int x, y, w;
}a[M], t[M];
bool cmp (Node a, Node b){
	return a.w < b.w;
}
int query (int x){
	if (x == fa[x]) return x;
	return fa[x] = query(fa[x]);
}
signed main (){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++ i) cin >> a[i].x >> a[i].y >> a[i].w;
	if (k == 0){
		sort(a + 1, a + m + 1, cmp);
		for (int i = 1; i <= n; ++ i) fa[i] = i;
		for (int i = 1; i <= m; ++ i){
			int x = query(a[i].x), y = query(a[i].y);
			if (x == y) continue;
			fa[y] = x;
			ans += a[i].w;
			++ cnt;
			if (cnt == n - 1) break;
		}
		cout << ans << '\n';
		return 0;
	}
	for (int i = 1; i <= k; ++ i){
		cin >> b[i];
		cnt += (b[i] == 0);
		for (int j = 1; j <= n; ++ j) cin >> c[i][j];
	}
	if (cnt == k){
		p = m;
		for (int i = 1; i <= n; ++ i){
			for (int j = i + 1; j <= n; ++ j){
				int maxn = 10000000000000000 * 1ll;
				for (int g = 1; g <= k; ++ g){
					maxn = min(maxn, c[g][i] + c[g][j]);	
				}
				++ p;
				a[p].x = i;
				a[p].y = j;
				a[p].w = maxn;
			}
		}
		sort(a + 1, a + p + 1, cmp);
		for (int i = 1; i <= n; ++ i) fa[i] = i;
		ans = cnt = 0ll;
		for (int i = 1; i <= p; ++ i){
			int x = query(a[i].x), y = query(a[i].y);
			if (x == y) continue;
			fa[y] = x;
			ans += a[i].w;
			++ cnt;
			if (cnt == n - 1) break;
		}
		cout << ans << '\n';
		return 0;
	}
	ans = 10000000000000000 * 1ll;
	for (int i = 0; i < (1ll << k); ++ i){
		sum = 0ll;
		p = m;
		for (int j = 1; j <= m; ++ j) t[j] = a[j];
		for (int j = 0; j < k; ++ j){
			if ((i >> j) & 1ll) sum += b[k - j];
		}
		for (int g = 1; g <= n; ++ g){
			for (int l = g + 1; l <= n; ++ l){
				int maxn = 10000000000000000 * 1ll;
				for (int j = 0; j < k; ++ j){
					if ((i >> j) & 1ll){
						maxn = min(maxn, c[k - j][g] + c[k - j][l]);
					}
				}
				++ p;
				t[p].x = g, t[p].y = l, t[p].w = maxn;
			}
		}
		for (int j = 1; j <= n; ++ j) fa[j] = j;
		sort(t + 1, t + p + 1, cmp);
		cnt = 0ll;
		for (int j = 1; j <= p; ++ j){
			int x = query(t[j].x), y = query(t[j].y);
			if (x == y) continue;
			fa[y] = x;
			sum += t[j].w;
			++ cnt;
			if (cnt == n - 1) break;
		}
		ans = min(ans, sum);
	}
	cout << ans << '\n';
	return 0;
}
