#include <iostream>
#include <algorithm>
using namespace std;

const int MXN = 1e5 + 5;
int T, n, cnt[4], clb[MXN], a[MXN][4];
int p, mst, tmp[MXN];
long long ans;

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> T;
	while (T--){
		ans = p = cnt[1] = cnt[2] = cnt[0] = 0;
		cin >> n;
		for (int i = 1; i <= n; i += 1){
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			int res = (a[i][0] > a[i][1] ? 0 : 1);
			res = (a[i][2] > a[i][res] ? 2 : res);
			cnt[res] += 1;
			ans += a[i][res];
			clb[i] = res;
			if (a[i][0] < a[i][1]) swap(a[i][0], a[i][1]);
			if (a[i][1] < a[i][2]) swap(a[i][1], a[i][2]);
			if (a[i][0] < a[i][1]) swap(a[i][0], a[i][1]);
		}
		mst = (cnt[0] < cnt[1] ? 1 : 0);
		mst = (cnt[2] < cnt[mst] ? mst : 2);
		for (int i = 1; i <= n; i += 1)
			if (clb[i] == mst) tmp[++p] = a[i][1] - a[i][0];
		sort(tmp + 1, tmp + p + 1);
		for (int i = (n >> 1) + 1; i <= p; i += 1) ans += tmp[i];
		cout << ans << '\n';
	}
	return 0;
}




