#include <bits/stdc++.h>
using namespace std;
int a[10],j;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i ++)
	    if (s[i] >= '0' && s[i] <= '9')
	        a[s[i] - '0'] ++;
	if (!a[9] && !a[8] && !a[7] && !a[6] && !a[5] && !a[4] && !a[3] && !a[2] && !a[1])
	{
		cout << 0 << '\n';
		return 0;
	}
	for (int i = 9; i >= 0; i --)
	{
		while (a[i])
		{
			a[i] --;
			cout << i;
		}
	}
	cout << '\n';
	return 0;
}
