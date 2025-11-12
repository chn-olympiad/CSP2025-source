#include <iostream>
#include <cstdio>
#include <string> 
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int l,a;
	cin >> s;
	l=s.length();
	for (int i=0;i<l;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a++;
		}
	}
	char b[a];
	a=0;
	for (int i=0;i<l;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			b[a]=s[i];
			a++;
		}
	}
	for (int i=0;i<a;i++)
	{
		for (int j=i;j<a;j++)
		{
			if (b[i]-'0'<b[j]-'0')
			{
				swap(b[i],b[j]);
			}
		}
	}
	for (int i=0;i<a;i++)
	{
		cout << b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
