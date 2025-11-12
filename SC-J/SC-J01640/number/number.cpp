#include<bits/stdc++.h>
using namespace std;
int number[15];
string s, ans = "";
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		char c = s[i];
		if (c >= '0' && c <= '9')
		{
			number[c - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--)
	{
		while (number[i]--)
		{
			ans += char('0' + i);
		}
	}
	cout << ans << endl;
	return 0;
}