#include<bits/stdc++.h>
using namespace std;
string s,s1;
int cnt=0;
bool cmp(char x,char y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(int(s[i])>=48&&int(s[i])<=57)
		{
			s1=s1+s[i];
		}
	}
	sort(s1.begin(),s1.end(),cmp);
	for(int i=0;i<s1.size();i++)
	{
		cout<<s1[i];
	}
	return 0;
} 
