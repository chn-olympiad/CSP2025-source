#include<bits/stdc++.h>
using namespace std;
const int N=0;
string s;
int t[15];
int l,c;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			t[s[i]-'0']++;
		}
	}
	for(int i=9;i>0;i--)
	{
		for(int j=1;j<=t[i];j++)
			cout<<i;
		if(t[i]>0)
			c=1;
	}
	
	if(c==0)
		cout<<0;
	else
	{
		for(int j=1;j<=t[0];j++)
			cout<<0;
	}
	
	return 0;
 } 