#include<bits/stdc++.h>
using namespace std;
int a[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			int x=s[i]-'0';
			a[x]++;
		}
	}
	bool f=0;
	for(int i=9;i>=1;i--)
	{
		if(a[i]>0)f=1;
		for(int j=1;j<=a[i];j++)
		{
			cout<<i;
		}
	}
	if(!f)cout<<0;
	else
	{
		for(int j=1;j<=a[0];j++)
		{
			cout<<0;
		}
	}
	return 0;
}