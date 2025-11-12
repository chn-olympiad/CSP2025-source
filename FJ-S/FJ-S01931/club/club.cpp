#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n, cnt[4], tot;
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t --) {
		tot = 0;
		cnt[1] = cnt[2] = cnt[3] = 0;
		//duo ce yao qing ling
		cin >> n;
		vector<vector<int>> a(n + 1, vector<int>(4, 0));
		vector<int> other(n + 1, 0), ans_idx(n + 1, 0);
		for(int i = 1; i <= n; ++ i) {
			int mx_idx = 0, mx = 0, sum = 0;
			int mi = 0x3f3f3f3f;
			for(int j = 1; j <= 3; ++ j) {
				cin >> a[i][j];
				sum += a[i][j];
				if(a[i][j] > mx) mx = a[i][j], mx_idx = j;
				mi = min(mi, a[i][j]);
			}
			int sec = sum - mx - mi;
			++ cnt[mx_idx];
			ans_idx[i] = mx_idx;
			other[i] = mx - sec;
			tot += mx;
		}
		int k = 0;
		if(cnt[1] > (n >> 1)) k = 1;
		else if(cnt[2] > (n >> 1)) k = 2;
		else if(cnt[3] > (n >> 1)) k = 3;
		if(k == 0) {
			cout << tot << '\n';
			continue;
		}
		int ck = cnt[k];
		vector<int> oths;
		for(int i = 1; i <= n; ++ i)
			if(ans_idx[i] == k)
				oths.push_back(other[i]);
		sort(oths.begin(), oths.end());
		//for(int i = 0; i < ck; ++ i) cout << oths[i] << " \n"[i == ck - 1]; //debug
		for(int i = 0; i < ck - (n >> 1); ++ i)
			tot -= oths[i];
		cout << tot << '\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
