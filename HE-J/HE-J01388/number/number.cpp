#include<bits/stdc++.h>
using namespace std;
string s;
int len;
int t[11];
int c;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int k=0;k<len;k++)
	{
		if(s[k]>='0'&&s[k]<='9')
		{
			c=s[k]-48;
			t[c]=t[c]+1;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(t[i]!=0)
		{
			for(int j=1;j<=t[i];j++)
			{
				cout<<i;
			}
		}
	}
	return 0;
}
