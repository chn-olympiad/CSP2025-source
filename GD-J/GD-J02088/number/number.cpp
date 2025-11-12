#include<bits/stdc++.h>
using namespace std;
string s;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s; 
	if(s.size()==1)
	{
		cout<<s<<'\n';
		return 0;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<s.size();j++)
		if(s[j]-'0'==i)
		cout<<i;
	}
	cout<<'\n';
	return 0;
} 

