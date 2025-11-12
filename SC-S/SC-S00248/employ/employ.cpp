#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 505 + 5;
const ll MOD = 998244353;

ll n, m;

ll s[N], c[N], p[N];

int main () {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	string str; cin >> str;
	str = '#' + str;
	for (int i = 1; i <= n; i ++) s[i] = str[i] - '0';
	
	for (int i = 1; i <= n; i ++) cin >> c[i];
	
	for (int i = 1; i <= n; i ++) p[i] = i;
	
	ll tot = 0;
	do {
		ll cnt = 0, lq = 0; // 被拒绝或放弃参加面试人数  录取人数
		for (int i = 1; i <= n; i ++) {
			int id = p[i];
			if (cnt >= c[id]) {
				cnt ++;
				continue;
			}
			else {
				if (s[i] == 0) cnt ++;
				else lq ++;
			}
		}
		
		if (lq >= m) {
			tot ++;
			tot %= MOD;
		}
	} while (next_permutation(p + 1, p + n + 1));

	cout << tot % MOD << '\n';

	return 0;
}