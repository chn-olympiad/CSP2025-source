#include <bits/stdc++.h>
using namespace std;
int f[100];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,t;
	cin >> s;
	for (int i = 0;i < (int)s.size();i++) 
	{
		if (s[i] >= '0' && s[i] <= '9') f[s[i] - 48]++;
	}
	for (int i = 9;i >= 0;i--)
	{
		for (int j = 1;j <= f[i];j++) cout << i;
	}
	cout << '\n';
	return 0;
}
