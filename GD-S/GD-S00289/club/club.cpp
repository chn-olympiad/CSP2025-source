#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

const int maxn = 1e5+10;
PII a[maxn][10];
int dp[maxn], v[maxn];

PII check() {
	int maxx = -1, id = 0;
	for(int i=1; i<=3; i++) {
		if(maxx < dp[i]) {
			maxx = dp[i];
			id = i;
		}
	}
	return {maxx, id};
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	long long T, n, ans = 0;
	scanf("%lld", &T);
	while(T--) {
		memset(dp, 0, sizeof(dp));
		ans = 0;
		scanf("%lld", &n);
		for(int i=1; i<=n; i++) {
			scanf("%d%d%d", &a[i][1].first, &a[i][2].first, &a[i][3].first);
			a[i][1].second = 1;
			a[i][2].second = 2;
			a[i][3].second = 3;
			sort(a[i]+1, a[i]+4); 
		}
		for(int i=1; i<=n; i++) {
			++dp[a[i][3].second];
			ans += a[i][3].first;
		}
		PII t = check();
		int tot = 0;
		if(t.first > (n / 2)) {
			for(int i=1; i<=n; i++) {
				if(a[i][3].second == t.second) {
					v[++tot] = a[i][3].first-a[i][2].first;
				}
			}
			sort(v+1, v+tot+1);
			for(int i=1; i<=t.first-(n/2); i++) {
				ans -= v[i];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

