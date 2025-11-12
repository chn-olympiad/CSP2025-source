#include<bits/stdc++.h>
using namespace std;
string s;
int a[1001];
signed main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout); 
	cin >> s;
	int sz = s.size();
	for(int i = 0; i < sz; i++)
	{
		if('0' <= s[i] && s[i] <= '9')
		{
			a[s[i] - '0']++;
		}
	}
	bool f = 0;
	for(int i = 1; i <= 9; i++)
	{
		if(a[i] != 0)
		{
			f = 1;
		}
	}
	if(f == 0 && a[0] > 0)
	{
		cout << 0;
		return 0;
	}
	for(int i = 9; i >= 0; i--)
	{
		for(int j = 1; j <= a[i]; j++)
		{
			cout << i;
		}
	}
}
