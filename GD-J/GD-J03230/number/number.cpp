#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	string str;
	
	cin >> str;
	
	sort(str.begin(), str.end());
	
	for (int i = str.size() - 1; i >= 0; --i)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			cout << str[i];
		}
	}
	
	return 0;
}
