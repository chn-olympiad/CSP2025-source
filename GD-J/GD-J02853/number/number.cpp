#include <bits/stdc++.h>
using namespace std;

int a[15];

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	bool f = false;
	string s;
	cin >> s;
	int l = s.size();
	memset(a, 0, sizeof(a));
	
	for (int i = 0; i < l; i++)
	{
		char c = s[i];
		
		if (c >= '0' && c <= '9')
		{
			int num = c - '0';
			a[num]++;
			
			if (num != 0)
			{
				f = true;
			}
		}
	}
	
	if (!f)
	{
		cout << 0;
	}
	else
	{
		for (int i = 9; i >= 0; i--)
		{
			for (int j = 1; j <= a[i]; j++)
			{
				cout << i;
			}
		}
	}
	
	return 0;
}

