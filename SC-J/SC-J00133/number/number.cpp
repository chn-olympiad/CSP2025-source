#include<bits/stdc++.h>
using namespace std;
int a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie();cin.tie();
	string s;int sum=0;
	cin>>s;
	for(int i=0;i < s.length();i++)
	{
		if('0'<=s[i] and s[i]<='9')
		{
			a[s[i]-'0']++;sum++;
		}
	}
	if(a[0]==sum)
	{
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}