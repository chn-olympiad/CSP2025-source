#include <bits/stdc++.h>
using namespace std;
int t, n, a[200001][5], b[5][200001], cnt[5], sum;
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--){
		cin >> n; sum = cnt[1] = cnt[2] = cnt[3] = 0;
		for (int i = 1; i <= n; i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][1] > a[i][2] && a[i][1] > a[i][3]) b[1][++cnt[1]] = a[i][1] - max(a[i][2], a[i][3]), sum += a[i][1];
			if (a[i][2] > a[i][1] && a[i][2] > a[i][3]) b[2][++cnt[2]] = a[i][2] - max(a[i][1], a[i][3]), sum += a[i][2];
			if (a[i][3] > a[i][2] && a[i][3] > a[i][1]) b[3][++cnt[3]] = a[i][3] - max(a[i][2], a[i][1]), sum += a[i][3];
		}
		for (int i = 1; i <= 3; i++) sort(b[i] + 1, b[i] + cnt[i] + 1);
		for (int i = 1; i <= 3; i++){
			if (cnt[i] > n / 2){
				for (int j = 1; j <= cnt[i] - n / 2; j++) sum -= b[i][j];
			}
		}
		cout << sum << '\n';
	}
	return 0;
}
