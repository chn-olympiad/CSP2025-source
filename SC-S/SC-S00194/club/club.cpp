#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 100009, _INF = LONG_LONG_MIN;
struct peason {
	int a, b, c;
}p[N];
bool cmp(peason a, peason b) {
	return a.a > b.a;
}
int _, n, at[N], ans, nob, noc;
priority_queue<pair<int, int> > a2b, ka, kb, kc, a2c, b2c;
void dfs(int p1, int p2, int p3, int api) {
	if (p1 > n / 2 || p2 > n / 2 || p3 > n / 2) return;
	int x = p1 + p2 + p3 + 1;
	if (x > n) {
		ans = max(ans, api);
		return;
	}
	dfs(p1 + 1, p2, p3, api + p[x].a);
	dfs(p1, p2 + 1, p3, api + p[x].b);
	dfs(p1, p2, p3 + 1, api + p[x].c);
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	for (cin >> _; _--; ) {
		nob = 1, noc = 1, ans = 0;
		cin >> n;
		for (int i  = 1; i <= n; i++)
			cin >> p[i].a >> p[i].b >> p[i].c, nob &= (p[i].b == 0), noc &= (p[i].c == 0);
		if (n <= 10) {
			dfs(0, 0, 0, 0);
			cout << ans << '\n';
			continue;
		}
		if (nob && noc) {
			sort(p + 1, p + n + 1, cmp);
			for (int i = 1; i <= n / 2; i++) ans += p[i].a;
			cout << ans << '\n';
			continue;
		}
		if (noc) {
			while (ka.size()) ka.pop();
			while (a2c.size()) a2c.pop();
			while (b2c.size()) b2c.pop();
			sort(p + 1, p + n + 1, cmp);
			for (int i = 1; i <= n / 2; i++) a2b.push({p[i].b - p[i].a, i}), at[i] = 1;
			for (int i = n / 2 + 1; i <= n; i++) ka.push({p[i].a, i});
			while (1) {
				pair<int, int> a2 = {_INF, 0}, k2a = {_INF, 0};
				while (a2b.size() && at[a2b.top().second] != 1) a2b.pop();
				if (a2b.size()) a2 = a2b.top();
				while (ka.size() && at[ka.top().second] != 0) ka.pop();
				if (ka.size()) k2a = ka.top();
				int af = a2.first, k2f = k2a.first;
				if (af <= 0 && k2f <= 0) break;
				if ((b2c.size() < n / 2 && a2b.size() == n / 2 ) || (b2c.size() < n / 2 && a2b.size() < n / 2 && af > k2f)) {
					int as = a2.second;
					a2b.pop();
					b2c.push({p[as].c - p[as].b, as});
					at[as] = 2;
				}
				else if ((b2c.size() == n / 2 && a2b.size() < n / 2 ) || (b2c.size() < n / 2 && a2b.size() < n / 2 && af <= k2f)){
					int k2s = k2a.second;
					ka.pop();
					a2b.push({p[k2s].b - p[k2s].a, k2s});
					at[k2s] = 1;
				} else break;
			}
			for (int i = 1; i <= n; i++){
				if (at[i] == 1) ans += p[i].a;
				else ans += p[i].b;
				at[i] = 0;
			}
			cout << ans << '\n';
		}
	}
}/*

*/