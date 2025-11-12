#include <bits/stdc++.h>
using namespace std;
long long a[500001];
long long n, ans;
bool flag = true;
bool cmp(long long x, long long y) {
	return x < y;
}
void dfs(long long sum, long long maxn, long long cnt, long long id) {
	if (sum > maxn * 2 && cnt >= 3) {
		ans++;
//		cout << sum << " " << maxn << "" << cnt << endl;
	}
	cnt++;
	for (long long i = id + 1; i <= n; i++) {
		dfs(sum + a[i],max(maxn,a[i]),cnt,i);
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1) {
			flag = false;
		}
	}
	if (flag) {
		cout << n - 2;
		return 0;
	}
	sort(a + 1,a + n + 1,cmp);
	for (long long i = 1; i <= n - 3; i++) {
		if (a[i] == a[i - 1]) {
			continue;
		}
		dfs(a[i],a[i],1,i);
	}
	cout << ans % 998244353;
	return 0;
}
