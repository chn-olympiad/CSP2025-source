#include<bits/stdc++.h>
using namespace std;
int a[11];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int t=0;
	int l=s.size();
	for(int i=0;i<l;i++)
	{
		if(s[i]>='1'&&s[i]<='9')
		{
			a[s[i]-'0']++;
		}
		else if(s[i]=='0')
		t++;
	}
	for(int i=10;i>=1;i--)
	{
		for(int j=1;j<=a[i];j++)
		{
			cout<<i;
		}
	}
	for(int i=1;i<=t;i++)
	cout<<0;
	return 0;
}
