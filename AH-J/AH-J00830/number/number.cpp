#include<bits/stdc++.h>
using namespace std;
int a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	bool x=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')a[s[i]-'0']++;
	}
	for(int i=9;i>0;i--)
	{
		for(int j=0;j<a[i];j++)
		{
			cout<<i;
			if(x==0)x=1;
		}
	}
	if(a[0]>0)
	{
		if(x==0)cout<<'0';
		else
		{
			for(int j=0;j<a[0];j++)
			{
				cout<<'0';
			}
		}
	}
	return 0;
}
