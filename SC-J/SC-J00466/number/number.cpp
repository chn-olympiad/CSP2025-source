#include <bits/stdc++.h>
using namespace std;
string s,ans="";
int num[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (char&ch:s)
	{
		if (ch>='0'&&ch<='9')
		{
			ch-='0';
			num[(int)ch]++;
		}
	}
	for (int i=9;i>=0;i--)
		for (int j=num[i];j>0;j--)
			ans+=(char)i+'0';
	cout<<ans;
	return 0;
}