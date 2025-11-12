#include <bits/stdc++.h>
using namespace std;
string s;
int book[15],flag=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			book[s[i]-'0']++;
			if(s[i]-'0')
			{
				flag=1;
			}
		}
	}
	if(flag)
	{
		for(int i=9;i>=0;i--)
		{
			while(book[i]--)
			{
				cout<<i;
			}
		}
	}
	else
	{
		cout<<0;
	}
	return 0;
}
