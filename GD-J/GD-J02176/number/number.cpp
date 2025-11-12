#include <bits/stdc++.h>
using namespace std;
string a,c;
string b[10005];
int main()
{
	cin >> a;
	for (int i = 0;i <= a.size();i++)
	{
		if (a[i] == '0')
		{
			b[i] = a[i];
		}
		else if (a[i] == '1')
		{
			b[i] = a[i];
		}
		else if (a[i] == '2')
		{
			b[i] = a[i];
		}
		else if (a[i] == '3')
		{
			b[i] = a[i];
		}
		else if (a[i] == '4')
		{
			b[i] = a[i];
		}
		else if (a[i] == '5')
		{
			b[i] = a[i];
		}
		else if (a[i] == '6')
		{
			b[i] = a[i];
		}
		else if (a[i] == '7')
		{
			b[i] = a[i];
		}
		else if (a[i] == '8')
		{
			b[i] = a[i];
		}
		else if (a[i] == '9')
		{
			b[i] = a[i];
		}
	}
	sort(b,b + a.size() + 1);
	for (int i = a.size();i >= 0;i--)
	{
		c += b[i];
	}
	cout << c;
	return 0;
} 
