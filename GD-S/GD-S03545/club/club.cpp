#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int N = 1e5+100;

struct P {
	int a1, a2, a3, maxn = 0;
}s[N];

bool cmp (P x, P y) {
	return x.maxn > y.maxn;
}

int dp[N][3], cnt[N][3][3], n;
ll ans;

void dfs (int now, ll res, int _1, int _2, int _3) {
	if (now > n) { ans = max(ans, res); return; }
	for (int i = 0;i < 3;i++) {
		if (i == 0 && _1 < n/2) {
			ll nex = res + s[now].a1;
			dfs(now+1, nex, _1+1, _2, _3);
		} else if (i == 1 && _2 < n/2) {
			ll nex = res + s[now].a2;
			dfs(now+1, nex, _1, _2+1, _3);
		} else if (i == 2 && _3 < n/2) {
			ll nex = res + s[now].a3;
			dfs(now+1, nex, _1, _2, _3+1);
		}
	}
}

void solve () {
	scanf("%d", &n);
	bool flag = false, _2 = true;
	for (int i = 1;i <= n;i++) {
		scanf("%d%d%d", &s[i].a1, &s[i].a2, &s[i].a3);
		if (s[i].a2 || s[i].a3) flag = true;
		if (s[i].a3) _2 = false;
		s[i].maxn = max(s[i].a1, max(s[i].a2, s[i].a3));
	}
	if (n <= 10) {
		ans = 0;
		dfs(1, 0, 0, 0, 0);
		printf("%lld\n", ans);
	} else if (!flag) {
		sort(s+1, s+n+1, cmp);
		ll ans = 0;
		for (int i = 1;i <= n/2;i++) ans += s[i].a1;
		printf("%lld\n", ans);
	} else if (_2) {
		sort(s+1, s+n+1, cmp);
		ll ans = 0, _1 = 0, _2 = 0;
		for (int i = 1;i <= n;i++) {
			if (s[i].a1 > s[i].a2) {
				if (_1 < n/2) ans += s[i].a1, _1++;
				else ans += s[i].a2, _2++;
			} else {
				if (_2 < n/2) ans += s[i].a2, _2++;
				else ans += s[i].a1, _1++;
			}
		}
		printf("%lld\n", ans);
	} 
	else {
		memset(cnt, 0, sizeof(cnt));
		dp[1][0] = s[1].a1, dp[1][1] = s[1].a2, dp[1][2] = s[1].a3;
		cnt[1][0][0] = cnt[1][1][1] = cnt[1][2][2] = 1;
		for (int i = 2;i <= n;i++) {
			for (int j = 0;j < 3;j++) {
				int pre = -1, tmp = 0, use = 0;
				if (j == 0) use = s[i].a1;
				else if (j == 1) use = s[i].a2;
				else use = s[i].a3;
				for (int z = 0;z < 3;z++) {
					cnt[i][j][z] = cnt[i-1][j][z];
					if (cnt[i-1][z][j] >= n/2) continue;
					if (tmp < dp[i-1][z] + use) tmp = dp[i-1][z] + use;
				}
				dp[i][j] = tmp;
				cnt[i][j][j]++;
			}
		}
		cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << "\n";
		return;
	}
} 

int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int _ = 1; scanf("%d", &_);
	while(_--) solve();
	return 0;
}
