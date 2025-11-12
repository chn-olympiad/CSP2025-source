#include <bits/stdc++.h>
using namespace std;
string s;
string a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	s=" "+s;
	int cnt = 1;
	for (int i = 1;i < s.length();i++)
	{
		if ((s[i]<='9')&&(s[i]>='0'))
		{
			a[cnt]=s[i];
			cnt++;
		}
	}
	for (int i = cnt;i >= 1;i--)
	{
		for (int j = 1;j <= i;j++)
		{
			if (a[j]<a[j+1])
			{
				string n = a[j];
				a[j]=a[j+1];
				a[j+1]=n;
			}
		}
	}
	for (int i = 1;i <= cnt;i++)
	{
		cout << a[i];
	}
	return 0;
}
