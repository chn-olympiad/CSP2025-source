#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 100005;ll ans;
int t, n, a[N][3], cnt[3], id[N];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> t;
	while (t --){cin >> n, cnt[0] = cnt[1] = cnt[2] = ans = 0;
		for (int i = 1;i <= n;i ++)
		for (int j : {0, 1, 2}) cin >> a[i][j];
		for (int i = 1;i <= n;i ++){
			if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) id[i] = 0;
			if (a[i][1] >= a[i][0] && a[i][1] >= a[i][2]) id[i] = 1;
			if (a[i][2] >= a[i][0] && a[i][2] >= a[i][1]) id[i] = 2;
			cnt[id[i]] ++, ans += a[i][id[i]];
		}int o = -1;vector<int> res;
		for (int j : {0, 1, 2}) if (cnt[j] * 2 > n) o = j;
		for (int i = 1;i <= n;i ++) if (id[i] == o){int z = 1000000000;
			for (int j : {0, 1, 2}) if (j != o) z = min(z, a[i][o] - a[i][j]);
			res.push_back(z);
		}sort(res.begin(), res.end());
		for (int i = 0;o != -1 && cnt[o] - i << 1 > n;i ++) ans -= res[i];cout << ans << '\n';
	}
}