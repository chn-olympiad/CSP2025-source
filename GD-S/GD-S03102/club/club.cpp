#include<bits/stdc++.h>
#define pii pair<int, int>
#define node pair<int, pair<pii, pair<int, pii>>>
#define fi first
#define se second
#define val1 fi
#define val2 se.fi.fi
#define val3 se.fi.se
#define id1 se.se.fi
#define id2 se.se.se.fi
#define id3 se.se.se.se
using namespace std;
int T, n, ans;
pii p[3];
priority_queue<node> q;
vector<int> d[4];
node inp() {
	p[0].se = 1, p[1].se = 2, p[2].se = 3;
	scanf("%d %d %d", &p[0].fi, &p[1].fi, &p[2].fi);
	sort(p, p + 3);
	reverse(p, p + 3);
	return {p[0].fi, {{p[1].fi, p[2].fi}, {p[0].se, {p[1].se, p[2].se}}}};
}
void solve() {
	for(int i = 1; i <= 3; i++) d[i].clear();
	ans = 0;
	cin >> n;
	for(int i = 0; i < n; i++) q.push(inp());
	while(!q.empty()) {
		auto i = q.top();
		q.pop();
		ans += i.val1;
		d[i.id1].push_back(i.val1 - i.val2);
	}
	for(int i = 1; i <= 3; i++) {
		if(d[i].size() > n / 2) {
			sort(d[i].begin(), d[i].end());
			for(int j = 0; j < d[i].size() - n / 2; j++) ans -= d[i][j];
			break;
		}
	}
	cout << ans << endl;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--) solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
