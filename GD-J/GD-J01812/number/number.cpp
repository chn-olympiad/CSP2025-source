#include<bits/stdc++.h>
using namespace std;
string str;
string s;
bool cmp(string sa,string sb)
{
	return (sa+sb)>(sb+sa);
}
int main()
{
	s="";
	cin>>str;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			s+=str[i];
		}
	}
	//cout<<s;
	int len=s.size();
	sort(s.begin(),s.end(),cmp);
	for(int i=0;i<len;i++)
	{
		cout<<s[i];
	}
	return 0;
}
//-O2 -std=c++14 -static
