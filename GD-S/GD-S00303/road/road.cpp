#include <bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define vi vetor<int>
#define sz(a) ((int)a.size())
#define mp make_pair
#define pb emplace_back
#define pii pair<int, int>
using namespace std;
const int N = 1e4 + 10, M = 5e6 + 10;
int n, m, k;
ll p[N], a[15][N];
vector<int> g[N];
struct Edge {
	int u, v;
	ll w;
	bool operator< (const Edge &t) const {
		return w < t.w; 
	} 
} edge[M], e[M];
int fa[N], siz[N];
bool st[M];
int find(int x) {
	if(fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}
ll ans;
void kruskal() {
	sort(e + 1, e + m + 1);
	int cnt = 0;
	L(i, 1, m) {
		int a = e[i].u, b = e[i].v;
		ll c = e[i].w;
//		cout << a << " " << b << " " << c << '\n';
		a = find(a), b = find(b);
		if(a != b) {
			if(siz[a] > siz[b]) swap(a, b);
			fa[a] = b;
			st[i] = 1;
			ans += c;
			cnt++;
		}
		if(cnt == n - 1) break;
	}
}
int cnt = 0, num;
ll ans2 = 0;
void kruskal2() {
	sort(e + 1, e + cnt + 1);
	int now = 0; ans2 = 0;
	L(i, 1, m) {
		int a = e[i].u, b = e[i].v;
		ll c = e[i].w;
		a = find(a), b = find(b);
		if(a != b) {
			if(siz[a] > siz[b]) swap(a, b);
			fa[a] = b;
			ans2 += c;
			now++;
		}
		if(now == num - 1) break;
	}
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	L(i, 1, n) fa[i] = i, siz[i] = 1; 
	for(int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[i] = {u, v, w};
	}
	bool flag = 1;
	L(i, 1, k) {
		cin >> p[i];
		if(p[i] != 0) flag = false; 
		L(j, 1, n) {
			cin >> a[i][j];
		} 
	}
	if(flag) {
		L(i, 1, k) {
			L(x, 1, n) {
				L(y, x + 1, n) {
					e[++m] = {x, y, a[i][x] + a[i][y] + p[i]};
				}
			}
		}
	}
	kruskal();
	if(k == 0 || flag) {
		cout << ans << '\n';
		return 0;
	}
	L(o, 0, (1 << k) - 1) {
		L(i, 1, n + k + 1) fa[i] = i, siz[i] = 1;
		cnt = m; num = n;
		ll w = 0; 
		for(int j = 0; j < k; j++) {
			if((o >> j) & 1) {
				w += p[j + 1];
				num++;
				for(int i = 1; i <= n; i++) {
					for(int p = i + 1; p <= n; p++) {
						e[++cnt] = {p, i, a[j + 1][i] + a[j + 1][p]};	
					} 
				}
			}
		}
		kruskal2();
//		cout << w << " " << ans2 << " " << '\n';
		ans = min(ans, ans2 + w);
	} 
	cout << ans << '\n';
	return 0;
} 
