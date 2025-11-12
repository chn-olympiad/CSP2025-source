#include <bits/stdc++.h>

using namespace std;

string s;
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	vector<int> v;
	for(int i = 0; i < s.length(); i++)
	{
		if('0' <= s[i] && s[i] <= '9')
			v.push_back(s[i] - '0');
	}
	sort(v.begin(), v.end(), cmp);
	for(int x : v) cout << x;
	return 0;
}

