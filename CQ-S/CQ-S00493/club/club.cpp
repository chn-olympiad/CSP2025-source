#include <bits/stdc++.h>

using namespace std;
int n, t, cnt[4];
long long ans;
struct node {
	int val[4], mx, nmx;
	bool operator <(const node &a) const &{
		return val[mx] > a.val[a.mx];
	}
} a[100005];
priority_queue<int, vector<int>, greater<int> > q;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t --) {
		cin >> n;
		cnt[1] = cnt[2] = cnt[3] = ans = 0;
		for(int i = 1; i <= n; i ++) {
			a[i].mx = a[i].nmx = 0;
			for(int j = 1; j <= 3; j ++) {
				cin >> a[i].val[j];
				if(a[i].val[j] >= a[i].val[a[i].mx])a[i].nmx = a[i].mx, a[i].mx = j;
				else if(a[i].val[j] >= a[i].val[a[i].nmx])a[i].nmx = j;
			}
			ans += a[i].val[a[i].mx];
			cnt[a[i].mx] ++;
		}
		for(int i = 1; i <= n; i ++) {
			if(cnt[a[i].mx] > n / 2) q.push(a[i].val[a[i].mx] - a[i].val[a[i].nmx]);
		}
		while(q.size()) {
			if(q.size() > n / 2) ans -= q.top();
			q.pop();
		}
		cout << ans << '\n';
	}
	return 0;
}

