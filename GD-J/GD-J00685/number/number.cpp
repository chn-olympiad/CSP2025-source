#include <iostream>
using namespace std;

int x[15] = {};

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s = "";
	cin >> s;
	for(int i = 0; i < s.size(); i++)
	{
		x[s[i] - '0']++;
	}
	string ans = "";
	for(int i = 9; i >= 0; i--)
	{
		while(x[i] != 0)
		{
			x[i]--;
			char da = '0' + i;
			ans = ans + da;
		}
	}
	cout << ans;
	return 0;
} 
