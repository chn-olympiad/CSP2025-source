#include<bits/stdc++.h>
using namespace std;
int a[100],n;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(isdigit(s[i]))
			a[(int)s[i]]++;
	}
	for(char i='9';i>=0;i--)
	{
		for(int j=1;j<=a[(int)i];j++)
			putchar(i);
	}
	return 0;
}
