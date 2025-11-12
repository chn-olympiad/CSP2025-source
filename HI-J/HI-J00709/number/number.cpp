#include<bits/stdc++.h>
using namespace std;
char a[1000001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0')
		{
			a[i]=s[i];
		}
		if(s[i]=='1')
		{
			a[i]=s[i];
		}
		if(s[i]=='2')
		{
			a[i]=s[i];
		}
		if(s[i]=='3')
		{
			a[i]=s[i];
		}
		if(s[i]=='4')
		{
			a[i]=s[i];
		}
		if(s[i]=='5')
		{
			a[i]=s[i];
		}
		if(s[i]=='6')
		{
			a[i]=s[i];
		}
		if(s[i]=='7')
		{
			a[i]=s[i];
		}
		if(s[i]=='8')
		{
			a[i]=s[i];
		}
		if(s[i]=='9')
		{
			a[i]=s[i];
		}
	}
	sort(a,a+s.size());
	for(int i=s.size()-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
 } 
