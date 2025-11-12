#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
	breopen("number.in" , "r" , stdin);
	breopen("number.out" , "w" , stdout);
	string s;
	cin >> s;
	char a[105];
	for(int i=0;i<105;i++)
	{
		if(s[i] != '1' || '2' || '3' || '4' || '5' || '6' || '7' || '8' || '9' || 'a' || 'b' || 'c' || 'd' || 'e' || 'f' || 'g' || 'h' || 'i' || 'j' || 'k' || 'l' || 'm' || 'n' || 'o' || 'p' || 'q' || 'r' || 's' || 't' || 'u' || 'v' || 'w' || 'x' || 'y' || 'z')
		{
			break;
		}
		a[i] = s[i];
	}
	char b[105];
	for(int i=0;i<105;i++)
	{
		if(a[i] == '9')
		{
			cout << a[i];
		}
		else
		{
			b[i] = a[i];
		}
	}
	char c[105];
	for(int i=0;i<105;i++)
	{
		if(b[i] == '8')
		{
			cout << b[i];
		}
		else
		{
			c[i] = b[i];
		}
	}
	char d[105];
	for(int i=0;i<105;i++)
	{
		if(c[i] == '7')
		{
			cout << c[i];
		}
		else
		{
			d[i] = c[i];
		}
	}
	char e[105];
	for(int i=0;i<105;i++)
	{
		if(d[i] == '6')
		{
			cout << d[i];
		}
		else
		{
			e[i] = d[i];
		}
	}
	char f[105];
	for(int i=0;i<105;i++)
	{
		if(e[i] == '5')
		{
			cout << e[i];
		}
		else
		{
			f[i] = e[i];
		}
	}
	char g[105];
	for(int i=0;i<105;i++)
	{
		if(f[i] == '4')
		{
			cout << f[i];
		}
		else
		{
			g[i] = f[i];
		}
	}
	char h[105];
	for(int i=0;i<105;i++)
	{
		if(g[i] == '3')
		{
			cout << g[i];
		}
		else
		{
			h[i] = g[i];
		}
	}
	char p[105];
	for(int i=0;i<105;i++)
	{
		if(h[i] == '2')
		{
			cout << h[i];
		}
		else
		{
			p[i] = h[i];
		}
	}
	char j[105];
	for(int i=0;i<105;i++)
	{
		if(p[i] == '1')
		{
			cout << p[i];
		}
		else
		{
			j[i] = p[i];
		}
	}
	for(int i=0;i<105;i++)
	{
		if(j[i] == '0')
		{
			cout << j[i];
		}
	}
	return 0;
}
