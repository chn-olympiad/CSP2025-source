#include <bits/stdc++.h>
using namespace std;

struct JZ {
	int val, cl, id;
}s[300005];
int t, n, ans;
int a[100005][5];
bool vis[100005];
bool cmp(JZ x, JZ y) {
	if (x.val == y.val) {
		if (x.id == y.id) return x.cl < y.cl;
		return x.id < y.id;
	}
	return x.val < y.val;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		vector <int> v[5];
		ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) scanf("%d", &a[i][j]);
			int k = max(a[i][1], max(a[i][2], a[i][3]));
			if (k == a[i][1]) v[1].push_back(i);
			else if (k == a[i][2]) v[2].push_back(i);
			else v[3].push_back(i);
			ans += k;
		}
		memset(vis, 0, sizeof vis);
		if (v[1].size() > n/2) {
			int cur = 0;
			for (auto i:v[1]) {
				s[++cur] = {a[i][1]-a[i][2], 2, i};
				s[++cur] = {a[i][1]-a[i][3], 3, i}; 
			}
			sort(s+1, s+cur+1, cmp);
			int cnt = 0;
			for (int i = 1; i <= cur; i++) {
				if (vis[s[i].id]) continue;
				ans -= s[i].val, cnt++, vis[s[i].id] = 1;
				if (v[1].size()-cnt == n/2) break;
			}
		}
		if (v[2].size() > n/2) {
			int cur = 0;
			for (auto i:v[2]) {
				s[++cur] = {a[i][2]-a[i][1], 1, i};
				s[++cur] = {a[i][2]-a[i][3], 3, i}; 
			}
			sort(s+1, s+cur+1, cmp);
			int cnt = 0;
			for (int i = 1; i <= cur; i++) {
				if (vis[s[i].id]) continue;
				ans -= s[i].val, cnt++, vis[s[i].id] = 1;
				if (v[2].size()-cnt == n/2) break;
			}
		}
		if (v[3].size() > n/2) {
			int cur = 0;
			for (auto i:v[3]) {
				s[++cur] = {a[i][3]-a[i][1], 1, i};
				s[++cur] = {a[i][3]-a[i][2], 2, i}; 
			}
			sort(s+1, s+cur+1, cmp);
			int cnt = 0;
			for (int i = 1; i <= cur; i++) {
				if (vis[s[i].id]) continue;
				ans -= s[i].val, cnt++, vis[s[i].id] = 1;
				if (v[3].size()-cnt == n/2) break;
			}
		}
		printf("%d\n", ans);
	} 
	return 0;
}
