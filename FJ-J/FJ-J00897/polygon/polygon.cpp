#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, a[5001], maxn;
map<int, int> mp;
bool cmp(int x, int y) {
	return x > y;
}
int count(int x) {
	mp.clear();
	int cnt = 0;
	long long cnt2 = 0;
	mp[0] = 1;
	for(int i = 1; i < x; i ++) cnt += a[i];
	//cout << cnt << '\n';
	for(int i = 1; i < x; i ++) {
		for(int j = cnt; j >= a[i]; j --) {
			if(mp[j - a[i]] <= 0) continue;
			mp[j] += mp[j - a[i]];
		}
	}
	for(int j = a[x] + 1; j <= cnt; j ++) {
		cnt2 += mp[j];
		cnt2 %= mod;
	}
	return cnt2;
}
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%d", &a[i]), maxn = max(maxn, a[i]);
	if(n <= 2) cout << 0, exit(0);
	else if(n <= 3) {
		if(max(a[1], max(a[2], a[3])) * 2 >= a[1] + a[2] + a[3]) printf("0");
		else printf("1");
	}
	else if(maxn == 1) {
		int res = 0;
		long long ans = 0;
		for(int i = 1; i <= n; i ++) {
			if(a[i] == 1) res ++;
		}
		ans = (long long)(res) * (res - 1) * (res - 2) / 6 % mod;
		printf("%lld", ans);
	}
	else {
		sort(a + 1, a + n + 1);
		int res = 0;
		long long ans = 0;
		for(int i = 3; i <= n; i ++) {
			//cout << count(i) << ' ';
			ans += count(i);
			ans %= mod;
		}
		//cout << '\n';
		printf("%lld", ans);
	}
	return 0;
}
