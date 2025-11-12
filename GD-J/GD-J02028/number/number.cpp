#include <bits/stdc++.h>
using namespace std;
string s;
int cnt[20];
int main() {
	freopen("number.in", "r", stdin), freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		if (isdigit(s[i])) cnt[s[i] - 48]++;
	for (int i = 9; i >= 0; i--) for (int j = 1; j <= cnt[i]; j++) cout << i;
	return 0;
}
