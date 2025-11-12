#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	string s;
	cin >> s;
	int ans = 0;
	string b[245];
	for (int i = 0 ; i <= s.length() - 1 ; ++i)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			b[ans] = s[i];
			ans++;
		}
	}
	sort(b,b+ans);
	for (int i = ans - 1 ; i >= 0 ; --i )
	{
		cout << b[i];
	}
	return 0;
}
