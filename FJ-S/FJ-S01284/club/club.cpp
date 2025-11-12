/*

先不考虑限制把最优情况写出来。

若有一组超过限制，则从这组里挑选若干个人放到其他组，使这组满足限制且答案最大。

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, T, a[100002][3], ans;
vector<ll> v[12];
bool cmp1(ll x, ll y) {
	return max(a[x][2], a[x][3]) - a[x][1] > max(a[y][2], a[y][3]) - a[y][1];
}
bool cmp2(ll x, ll y) {
	return max(a[x][1], a[x][3]) - a[x][2] > max(a[y][1], a[y][3]) - a[y][2];
}
bool cmp3(ll x, ll y) {
	return max(a[x][2], a[x][1]) - a[x][3] > max(a[y][2], a[y][1]) - a[y][3];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while (T -- ) {
		cin >> n;
		ans = 0;
		v[1].clear(), v[2].clear(), v[3].clear();
		for (ll i = 1; i <= n; i ++ ) for (ll j = 1; j <= 3; j ++ ) cin >> a[i][j];
		for (ll i = 1; i <= n; i ++ ) {
			if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) v[1].push_back(i), ans += a[i][1];
			if (a[i][2] > a[i][1] && a[i][2] >= a[i][3]) v[2].push_back(i), ans += a[i][2];
			if (a[i][3] > a[i][1] && a[i][3] > a[i][2]) v[3].push_back(i), ans += a[i][3];
		}
		if (v[1].size() > n / 2) {
			sort(v[1].begin(), v[1].end(), cmp1);
			for (ll i = 0; i < v[1].size() - n / 2; i ++ ) {
				ll t = v[1][i];
				if (a[t][2] > a[t][3]) ans += a[t][2] - a[t][1];
				else ans += a[t][3] - a[t][1];
			}
		}
		if (v[2].size() > n / 2) {
			sort(v[2].begin(), v[2].end(), cmp2);
			for (ll i = 0; i < v[2].size() - n / 2; i ++ ) {
				ll t = v[2][i];
				if (a[t][1] > a[t][3]) ans += a[t][1] - a[t][2];
				else ans += a[t][3] - a[t][2];
			}
		}
		if (v[3].size() > n / 2) {
			sort(v[3].begin(), v[3].end(), cmp3);
			for (ll i = 0; i < v[3].size() - n / 2; i ++ ) {
				ll t = v[3][i];
				if (a[t][2] > a[t][1]) ans += a[t][2] - a[t][3];
				else ans += a[t][1] - a[t][3];
			}
		}
		cout << ans << "\n";
	}
}
/*
1
10
5491 4476 6362
9805 9130 15480
9090 9901 10480
6326 6516 1985
9119 2924 6420
9826 12689 7592
7293 16544 12901
11905 18183 18712
9015 3463 13025
1792 2433 17042
*/
