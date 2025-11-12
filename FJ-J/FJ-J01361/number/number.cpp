# include <bits/stdc++.h>
using namespace std;
string s;
vector < int > vec;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> s;
	for (char ch : s)
	{
		if (ch >= '0' && ch <= '9')
		{
			vec.push_back(ch - '0');
		}
	}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	for (int x : vec)
	{
		cout << x;
	}
	return 0;
}

