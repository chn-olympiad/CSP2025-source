#include <bits/stdc++.h>
using namespace std;

int dic[50], cur = 0;
string s, ans;

int main()
{
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	
	cin >> s;
	s = ' ' + s;
	int n = s.size();
	for (int i = 1; i <= n; i++)
	{
		if (s[i] >= 48 && s[i] <= 57)
		{
			dic[s[i] - 48]++;
		}
	} 
	for (int i = 9; i >= 0; i--)
	{
		while (dic[i] > 0)
		{
			dic[i]--;
			ans += i + '0';
		}
	}
	cout << ans;
	
	return 0;
}
