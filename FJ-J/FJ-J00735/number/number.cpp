#include <bits/stdc++.h>
//#define int long long
using namespace std;

string s;
int cnt[10];

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		if ('0' <= s[i] && s[i] <= '9') cnt[s[i] - '0']++;
	for (int t = 9; t >= 0; t--) for (int i = 0; i < cnt[t]; i++) cout << t;
}
