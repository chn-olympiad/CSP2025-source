#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
int n, b[10];
signed main()
{
	
	freopen("number.in", "r", "std.in");
	freopen("number.out", "w", "std::cout");
	
	std::cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			b[s[i] - '0']++;
		}
	}
	
	for (int i = 9; i >= 0; i--)
	{
		for (int j = b[i]; j > 0; j--)
		{
			std::cout << i;
		}
	}
	
	return 0;
} 
