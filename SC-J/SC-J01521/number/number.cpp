#include <bits/stdc++.h>
using namespace std;
string s, num;
int t[10];


int main()
{
	freopen("number.in", "r", stdin);
	
	getline(cin, s);
	
	for (int i = 0;i < s.size();i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			t[int(s[i]) - '0']++;
		}
	}
	
	for (int i = 9;i >= 0;i--)
	{
		while (t[i] > 0)
		{
			num += (char(i) + '0');
			t[i]--;
		}
	}
	
	freopen("number.out", "w", stdout);
	
	cout << num;
	
	
	return 0;
}