#include <iostream>
#include <string>

using namespace std;


int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s = "";
	string a = "";
	cin>>s;
	int max = 0,c = 0;
	
	if(s.length()==1)
	{
		cout<<s;
		return 0;
	}
	
	for(int i = 0;i<s.length();++i)
	{
		if(s[i]==57)
		{
			a.push_back(s[i]);
		}
	}
	for(int i = 0;i<s.length();++i)
	{
		if(s[i]==56)
		{
			a.push_back(s[i]);
		}
	}
	for(int i = 0;i<s.length();++i)
	{
		if(s[i]==55)
		{
			a.push_back(s[i]);
		}
	}
	for(int i = 0;i<s.length();++i)
	{
		if(s[i]==54)
		{
			a.push_back(s[i]);
		}
	}
	for(int i = 0;i<s.length();++i)
	{
		if(s[i]==53)
		{
			a.push_back(s[i]);
		}
	}
	for(int i = 0;i<s.length();++i)
	{
		if(s[i]==52)
		{
			a.push_back(s[i]);
		}
	}
	for(int i = 0;i<s.length();++i)
	{
		if(s[i]==51)
		{
			a.push_back(s[i]);
		}
	}
	for(int i = 0;i<s.length();++i)
	{
		if(s[i]==50)
		{
			a.push_back(s[i]);
		}
	}for(int i = 0;i<s.length();++i)
	{
		if(s[i]==49)
		{
			a.push_back(s[i]);
		}
	}
	for(int i = 0;i<s.length();++i)
	{
		if(s[i]==48)
		{
			a.push_back(s[i]);
		}
	}
	
	cout<<a;
	
	return 0;
} 