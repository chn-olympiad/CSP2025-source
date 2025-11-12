#include<bits/stdc++.h>
using namespace std;
string s,s1;
int a[11];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)s1+=(i+'0');
	}
	if(s1[0]=='0')cout<<0;
	else cout<<s1;
	return 0;
}
