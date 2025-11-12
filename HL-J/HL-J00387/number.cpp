#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	
	int x=0,a[10001];
	for (int i=0;i<strlen(s);i++)
	{
		if (isdigit(s[i]))
		{
			a[x]=s[i];
			x++;
		}
	}
	
	sort(a+1,a+x+1);
	
	for (int i=0;i<strlen(s);i++)
	{
		cout<<a[i];
	}
	return 0;
} 

