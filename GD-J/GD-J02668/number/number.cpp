#include <bits/stdc++.h>
using namespace std;
string s;
int nber[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (int i = 0;i < s.size();i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			int x = s[i] - '0';
			nber[x]++;
		}
	}
	for (int i = 9;i >= 0;i--)
	{
		for (int j = nber[i];j >= 1;j--)
		{
			cout << i;
		}
	}
	return 0;
} 
