#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	string t = "";
	int n = s.length();
	for (int i = 0; i < n; i++)
		if (s[i] >= '0' && s[i] <= '9')
			t += s[i];
	sort(t.begin(), t.end());
	for (int i = t.length() - 1; i >= 0; i--)
		cout << t[i];
	cout << endl;
	return 0;
}
