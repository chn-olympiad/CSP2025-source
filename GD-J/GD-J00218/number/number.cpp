#include<bits/stdc++.h>
using namespace std;
int read()
{
	int tmp=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		tmp=(tmp<<1)+(tmp<<3)+c-'0';
		c=getchar();
	}
	return tmp*f;
}
string s;
int a[101];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(a[i]!=0)
		{
			cout<<i;
			a[i]--;
		}
	}
	return 0;
}
