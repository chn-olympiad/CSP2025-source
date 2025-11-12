#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, q;
string str1[N], str2[N], ask, to;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	cin >> n >> q;
	for (int i = 1; i <= n; i ++) {
		cin >> str1[i] >> str2[i];
	}
	for (int i = 1; i <= q; i ++) {
		cin >> ask >> to;
		int ans = 0;
		for (int j = 1; j <= n; j ++) {
			bool flag = 0;
			for (int k = 0; k <= max(0, int(ask.size() - str1[j].size())); k ++) {
				if (ask.substr(k, str1[j].size()) != str1[j]) continue;
				string tmp = ask.substr(0, k) + str2[j] + ask.substr(min(ask.size(), k + str1[j].size()));
				if (tmp == to) {
					flag = 1;
					break;
				}
			}
			ans += flag;
		}
		cout << ans << '\n';
	}
	return 0;
}

/*
又是我，

我要上迷惑行为大赏！！！还有伊蕾娜我老婆 

Luogu: OIerElaina
*/

