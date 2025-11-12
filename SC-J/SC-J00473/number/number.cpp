#include<iostream>
#include<cstdio>
#include<string>
#include<vector>

using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<int>cnt(10,0);
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			cnt[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<cnt[i];j++)
		{
			putchar(char('0'+i));
		}
	}
	return 0;
}
