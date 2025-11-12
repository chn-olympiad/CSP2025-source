#include<bits/stdc++.h>
using namespace std;
string s,d;
int b=0,c=0,a[10005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>=48&&s[i]<=57)
		{
			a[b]=s[i];
			b++;
		}
	}
	for(int i=0;i<b;i++)
	{
		for(int j=i;j<b;j++)
		{
			if(c<a[j])
			{
				c=a[j];
				a[j]=a[i];
				a[i]=c;
			}
		}
		c=0;
	}
	for(int i=0;i<b;i++)
	{
		cout<<char(a[i]);
	}
	return 0;
}
