#include <iostream>
#include <cstring>
using namespace std;
string s;
int n,a,b,c,d,e,f,g,h,j;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (int i = 1;i <= s.length();i++)
	{
		if (s[i] == 0)
		{
			n++;
		}
		if (s[i] == 1)
		{
			a++;
		}
		if (s[i] == 2)
		{
			b++;
		}
		if (s[i] == 3)
		{
			c++;
		}
		if (s[i] == 4)
		{
			d++;
		}
		if (s[i] == 5)
		{
			e++;
		} 
		if (s[i] == 6)
		{
			f++;
		}
		if (s[i] == 7)
		{
			g++;
		}
		if (s[i] == 8)
		{
			h++;
		}
		if (s[i] == 9)
		{
			j++;
		}
	}
	for (int i = 1;i <= j;i++)
	{
		cout << 9;
	}
	for (int i = 1;i <= h;i++)
	{
		cout << 8;
	}
	for (int i = 1;i <= g;i++)
	{
		cout << 7;
	}
	for (int i = 1;i <= f;i++)
	{
		cout << 6;
	}
	for (int i = 1;i <= e;i++)
	{
		cout << 5;
	}
	for (int i = 1;i <= d;i++)
	{
		cout << 4;
	}
	for (int i = 1;i <= c;i++)
	{
		cout << 3;
	}
	for (int i = 1;i <= b;i++)
	{
		cout << 2;
	}
	for (int i = 1;i <= a;i++)
	{
		cout << 1;
	}
	for (int i = 1;i <= n;i++)
	{
		cout << 0;
	}
	return 0;
}
