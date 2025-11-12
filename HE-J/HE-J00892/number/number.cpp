#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string s;
string num[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			num[s[i]-48]+=s[i];
		}
	}
	for(int i=9;i>=0;i--)
	{
		cout<<num[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
