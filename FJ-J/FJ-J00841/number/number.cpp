#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	map<int,int> a;
	for (int i = 0;i < s.length();i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			a[(int)s[i] - '0'] += 1;
		}
	}
	string e = "";
	for (int i = 9;i >= 0;i--)
	{
		for (int j = 1;j <= a[i];j++)
		{
			e += to_string(i);
		}
	}
	cout << e;
	return 0;
}
