#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
//#define int long long
using namespace std;
const int N = 1e5 + 10;

int n, a[N][3], flg[N], cnt[3], ans, p[N], idx;
void work() {
	cin >> n;
	ans = 0;
	cnt[0] = cnt[1] = cnt[2] = 0;
	for(int i = 1; i <= n; i ++) {
		for(int j = 0; j < 3; j ++) {
			cin >> a[i][j];
		} 
		if(a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) {
			cnt[0] ++, ans += a[i][0];
			flg[i] = 0;
		}
		else if(a[i][1] > a[i][0] && a[i][1] >= a[i][2]) {
			cnt[1] ++, ans += a[i][1];
			flg[i] = 1;
		}
		else {
			cnt[2] ++, ans += a[i][2];
			flg[i] = 2;
		}
	}
	idx = 0;
	int mx = (cnt[1] > n / 2 ? 1 : (cnt[2] > n / 2 ? 2 : 0));
	for(int i = 1; i <= n; i ++) {
		if(flg[i] == mx) {
			int smx = a[i][0] + a[i][1] + a[i][2] - max({a[i][0], a[i][1], a[i][2]}) - min({a[i][0], a[i][1], a[i][2]});
			p[++ idx] = -a[i][mx] + smx;
		}
	} 
	sort(p + 1, p + idx + 1, greater<int>());
	for(int i = 1; i <= idx && cnt[mx] > n / 2; i ++) {
		cnt[mx] --;
		ans += p[i];
	}
	cout << ans << '\n';
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout); 
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T --) work();
	
	return 0;
}
