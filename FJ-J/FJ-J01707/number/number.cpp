#include <bits/stdc++.h>
#define int long long
using namespace std;
string s, s1;

bool cmp (char a, char b) {
	return a > b;
}

void solve () {
	cin >> s;
	for (int i = 0; i < s.size(); i ++) {
		if (s[i] >= '0' && s[i] <= '9') {
			s1 += s[i];
		}
	}
	sort (s1.begin(), s1.end(), cmp);
	cout << s1;
}

signed main () {  // AC t1! 8:38 && t1 red? 
//	freopen ("number4.in", "r", stdin);
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	ios :: sync_with_stdio (false), cin.tie (0), cout.tie (0);
	solve ();

	return 0;
}

