#include<bits/stdc++.h>
using namespace std;
int ans[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int num=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			ans[(s[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=ans[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}
