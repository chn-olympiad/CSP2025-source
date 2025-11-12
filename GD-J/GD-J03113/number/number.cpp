#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
long long a[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long i,j;
	cin >> s;
	for (i=0;i<s.size();i++)
	{
		if (isdigit(s[i]))
		{
			a[s[i]-'0']+=1;
		}
	}
	for (i=10;i>=0;i--)
	{
		if (a[i]!=0)
		{
			for (j=1;j<=a[i];j++)
			{
				cout << i;
			}
		}
	}
	return 0;
} 
