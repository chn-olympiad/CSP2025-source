#include <iostream> 
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin >> a;
	for(int i = 0;i <= a.length();i ++)
	{
		if(a[i] == '9')
		{
			cout << 9;
		}
	}
	for(int i = 0;i <= a.length();i ++)
	{
		if(a[i] == '8')
		{
			cout << 8;
		}
	}for(int i = 0;i <= a.length();i ++)
	{
		if(a[i] == '7')
		{
			cout << 7;
		}
	}for(int i = 0;i <= a.length();i ++)
	{
		if(a[i] == '6')
		{
			cout << 6;
		}
	}for(int i = 0;i <= a.length();i ++)
	{
		if(a[i] == '5')
		{
			cout << 5;
		}
	}for(int i = 0;i <= a.length();i ++)
	{
		if(a[i] == '4')
		{
			cout << 4;
		}
	}
	for(int i = 0;i <= a.length();i ++)
	{
		if(a[i] == '3')
		{
			cout << 3;
		}
	}
	for(int i = 0;i <= a.length();i ++)
	{
		if(a[i] == '2')
		{
			cout << 2;
		}
	}
	for(int i = 0;i <= a.length();i ++)
	{
		if(a[i] == '1')
		{
			cout << 1;
		}
	}
	for(int i = 0;i <= a.length();i ++)
	{
		if(a[i] == '0')
		{
			cout << 0;
		}
	}
	return 0;
}
