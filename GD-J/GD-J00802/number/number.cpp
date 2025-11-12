#include <bits/stdc++.h> 
using namespace std;
string s;
int a[10];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0; i < s.length(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			a[(s[i]-'0')]++;
		}
	}
	string ans = "";
	for (int i = 9; i >= 0; i--)
	{
		while (a[i] > 0)
		{
			ans += (char)(i+'0');
			a[i]--;
		}
	}
	if (ans[0] == '0')
	{
		cout << 0;
		return 0;
	}
	cout << ans;
	return 0;
}
