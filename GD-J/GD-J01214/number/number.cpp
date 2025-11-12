#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=9;i>=1;i--)
	{
		for(int j=0;j<s.size();j++)
		{
			if(s[j]==char(i+'0')) cout<<s[j];
		}
	}
	for(int j=0;j<s.size();j++)
	{
		if(s[j]=='0') cout<<0;
	}
	return 0;
}
