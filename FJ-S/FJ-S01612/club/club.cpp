#include <bits/stdc++.h>
#define int long long
using namespace std;

int T, n, ans;

struct stu {
	int id, x, y, z;
}s[100005];

priority_queue<pair<int, int> > q1, q2, q3;

void dfs(int a, int sum, int t1, int t2, int t3) {
	if(a > n) {
		ans = max(sum, ans);
		return;
	}
	if(t1 < n / 2) dfs(a + 1, sum + s[a].x, t1 + 1, t2, t3);
	if(t2 < n / 2) dfs(a + 1, sum + s[a].y, t1, t2 + 1, t3);
	if(t3 < n / 2) dfs(a + 1, sum + s[a].z, t1, t2, t3 + 1);
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T --) {
		while(q1.size()) q1.pop();
		while(q2.size()) q2.pop();
		while(q3.size()) q3.pop();
		ans = 0;
		cin >> n;
		for(int i = 1;i <= n;i ++) {
			s[i].id = i;
			cin >> s[i].x >> s[i].y >> s[i].z;
			int maxn = max({s[i].x, s[i].y, s[i].z});
			if(maxn == s[i].x) {
				int minn = max(s[i].y, s[i].z);
				q1.push(make_pair(-(maxn - minn), i));
			}
			else if(maxn == s[i].y) {
				int minn = max(s[i].x, s[i].z);
				q2.push(make_pair(-(maxn - minn), i));
			}
			else if(maxn == s[i].z) {
				int minn = max(s[i].y, s[i].x);
				q3.push(make_pair(-(maxn - minn), i));
			}
		}
		if(n <= 10) {
			dfs(1, 0, 0, 0, 0);
			cout << ans << "\n";
			continue;
		}
		while(q1.size() > n / 2) {
			int t = q1.top().second;
			q1.pop();
			ans += max(s[t].y, s[t].z);
		}
		while(q2.size() > n / 2) {
			int t = q2.top().second;
			q2.pop();
			ans += max(s[t].x, s[t].z);
		}
		while(q3.size() > n / 2) {
			int t = q3.top().second;
			q3.pop();
			ans += max(s[t].x, s[t].y);
		}
		while(q1.size()) {
			int yy = q1.top().second;
			ans += s[yy].x;
			q1.pop();
		}
		while(q2.size()) {
			int yy = q2.top().second;
			ans += s[yy].y;
			q2.pop();
		}
		while(q3.size()) {
			int yy = q3.top().second;
			ans += s[yy].z;
			q3.pop();
		}
		cout << ans << "\n";
	}
	return 0;
}//¶à²âÒªÇå¿Õ£¡ 
