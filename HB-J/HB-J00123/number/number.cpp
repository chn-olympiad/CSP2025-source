#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int book[15]={};
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			book[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<book[i];j++)
		{
			cout<<i;
		}	
	}
	return 0;
}
