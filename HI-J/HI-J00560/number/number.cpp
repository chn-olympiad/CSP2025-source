#include<bits/stdc++.h>
using namespace std;


int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int sz=s.size();
	multiset<int>v;
	for(int i=0;i<sz;i++)
	{
		char c=s[i];
		if(c>='0'&&c<='9')
		{
			v.insert(c-'0');
		}
	}
	s="";
	for(auto t:v)
	{
		s=to_string(t)+s;
	}
	cout<<s;
	
	
	
	
	return 0;
}
