#include <bits/stdc++.h>
int a[1000005],x=0;
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			a[x] = int(s[i] - '0');
			x++;
		}
	}
	for (int i = 9; i >= 0; i--)
	{
		for (int j = 0; j < x; j++)
		{
			if (a[j] == i)
			{
				printf("%d",a[j]);
			}
		}
	}
	return 0;
}
