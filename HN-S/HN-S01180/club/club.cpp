#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 50;

int T, n, a[MAX_N][3];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			
		int cnt[3] = {}, ans = 0;
		for (int i = 1; i <= n; i++) {
			int maxi = max({a[i][0], a[i][1], a[i][2]});
			int t = max_element(a[i], a[i] + 3) - a[i];
			cnt[t]++, ans += a[i][t];
		}
		
		int t = max_element(cnt, cnt + 3) - cnt;
		if (cnt[t] <= n / 2) {
			cout << ans << '\n';
			continue;
		}
		
		priority_queue<int> q;
		for (int i = 1; i <= n; i++)
			if (max_element(a[i], a[i] + 3) - a[i] == t) {
				int tmp = -2e4;
				for (int j : {0, 1, 2})
					if (j != t)
						tmp = max(tmp, a[i][j] - a[i][t]);
				q.push(tmp);
			}
		
		while (cnt[t] > n / 2) {
			ans += q.top();
			q.pop();
			cnt[t]--;
		} 
		
		cout << ans << '\n';
	}
	return 0;
}
