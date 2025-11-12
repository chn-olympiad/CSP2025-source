#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
map <int, int> mp;
int len;
signed main () {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> s;
	len = s.size();
	for (int i = 0; i < len; ++i)
		if (s[i] >= '0' && s[i] <= '9')
			++mp[s[i] - '0'];
	for (int i = 9; i >= 0; --i)
		for (int j = 1; j <= mp[i]; ++j)
			cout << i;
	return 0;
}
