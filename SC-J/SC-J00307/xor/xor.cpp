#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 5e5 + 5;

ll n, k, ans;
ll a[N];

void dfs(ll id, ll cur_tot, ll cnt) {
	if (id == n + 1) {
		ans = max(ans, cnt);
		return;
	}

	if ((cur_tot ^ a[id]) == k) {
		dfs(id + 1, 0, cnt + 1);
	}
	else {
		dfs(id + 1, (cur_tot ^ a[id]), cnt); // 算进上一区间

		dfs(id + 1, a[id], cnt); // 新建区间
	}
}


int main () {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i ++) cin >> a[i];

	bool flag_A = true, flag_B = true;
	for (int i = 1; i <= n; i ++) {
		if (a[i] != 1) {
			flag_A = false;
		}
		if (a[i] != 1 && a[i] != 0) {
			flag_B = false;
		}
	}


	if (flag_A == false && flag_B == false) {
		if (n <= 25) {
			dfs(1, 0, 0);

			cout << ans << '\n';

			return 0;
		}
		else {
			ll tot = 0, lst = 0;
			for (int i = 1; i <= n; i ++) {
				if (lst == k) {
					tot ++;
					lst = a[i];
					continue;
				}
				
				bool flag = i % 2;
				if (flag) {
					lst = (lst ^ a[i]);
				}
				else lst = a[i];
			}
			
			cout << tot << '\n';
			return 0;
		}
	}

	if (k == 0) {
		if (flag_A == true) {
			cout << (1.0 * n / 2) << '\n';
			return 0;
		}
		else if (flag_B == true) {
			ll cnt = 0, lst = 0;
			for (int i = 1; i <= n; i ++) {
				if (a[i] == 0) {
					cnt ++;
					lst = 0;
				}
				else {
					if (lst == 1) {
						lst = 0;
						cnt ++;
					}
					else {
						lst = 1;
					}
				}
			}

			cout << cnt << '\n';
			return 0;
		}
	}
	else if (k == 1) {
		ll cnt = 0;
		for (int i = 1; i <= n; i ++) {
			if (a[i] == 1) cnt ++;
		}

		cout << cnt << '\n';

		return 0;
	}

	return 0;
}