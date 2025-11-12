#include <bits/stdc++.h>

using namespace std;

string s, ans;

inline int cmp(char x, char y) { return x > y; }

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> s;
	
	for (int i = 0; i < (int)s.size(); ++i)
		if (s[i] >= '0' && s[i] <= '9')	
			ans.push_back(s[i]);
	
	sort(ans.begin(), ans.end(), cmp);
	cout << ans << endl;
	
	return 0;
}
