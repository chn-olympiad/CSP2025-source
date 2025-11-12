#include<bits/stdc++.h>
using namespace std;
int n,t[20],c,flag;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			c=int(s[i])-48;
			t[c]++;
		}
	}
	for(int i=9;i>=1;i--)
	{
		if(t[i]) flag=1;
		for(int j=1;j<=t[i];j++)
		{
			cout<<i;
		}
	}
	if(!flag) cout<<0;
	else
	{
		for(int i=1;i<=t[0];i++)
		{
			cout<<0;
		}	
	}
	return 0;
}