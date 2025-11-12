#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
char shu[1000001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int z = 0;
	int a = 0,b = 0,c = 0,d = 0,e = 0,f = 0,g = 0,h = 0,j = 0,l = 0,cnt = 0;
	string s;
	cin >> s;
	for(int i = 0;i < s.size();i++)
	{
		if(s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9')
		{
			shu[z] = s[i];
			z++;
		}
	}
	for(int p = 0;p < z;p++)
	{
		if(shu[p] == '1')
		{
			a++;
		}	
		else if(shu[p] == '2')
		{
			b++;
		}
		else if(shu[p] == '3')
		{
			c++;
		}
		else if(shu[p] == '4')
		{
			d++;
		}
		else if(shu[p] == '5')
		{
			e++;
		}
		else if(shu[p] == '6')
		{
			f++;
		}
		else if(shu[p] == '7')
		{
			g++;
		}
		else if(shu[p] == '8')
		{
			h++;
		}
		else if(shu[p] == '9')
		{
			j++;
		}
		else if(shu[p] == '0')
		{
			l++;
		}
	}
	for(int i = 0;i < j;i++)
	{
		cout << '9';
	}
	for(int i = 0;i < h;i++)
	{
		cout << '8';
	}
	for(int i = 0;i < g;i++)
	{
		cout << '7';
	}
	for(int i = 0;i < f;i++)
	{
		cout << '6';
	}
	for(int i = 0;i < e;i++)
	{
		cout << '5';
	}
	for(int i = 0;i < d;i++)
	{
		cout << '4';
	}
	for(int i = 0;i < c;i++)
	{
		cout << '3';
	}
	for(int i = 0;i < b;i++)
	{
		cout << '2';
	}
	for(int i = 0;i < a;i++)
	{
		cout << '1';
	}
	for(int i = 0;i < l;i++)
	{
		cout << '0';
	}
  	fclose(stdin);
	fclose(stdout);
	return 0;
} 
