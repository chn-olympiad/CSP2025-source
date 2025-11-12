#include <bits/stdc++.h>
using namespace std;
int d[10];
string s;
bool flag=1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]-'0'!=0)
			flag=0;
		d[s[i]-'0']++;
	}
	if(flag)
	{
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=d[i];j++)
			cout<<i;
	}
	return 0;
}
