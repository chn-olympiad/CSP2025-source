#include<bits/stdc++.h>
using namespace std;
string s,ans;
char num[1000005];
int n;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			num[n]=s[i];
			n++;
		}
	}
	for(int i=0;i<=n+1;i++)
	{
		if(num[i]=='9')
		{
			ans+="9";
		}
	}
	for(int i=0;i<=n+1;i++)
	{
		if(num[i]=='8')
		{
			ans+="8";
		}
	}
	for(int i=0;i<=n+1;i++)
	{
		if(num[i]=='7')
		{
			ans+="7";
		}
	}
	for(int i=0;i<=n+1;i++)
	{
		if(num[i]=='6')
		{
			ans+="6";
		}
	}
	for(int i=0;i<=n+1;i++)
	{
		if(num[i]=='5')
		{
			ans+="5";
		}
	}
	for(int i=0;i<=n+1;i++)
	{
		if(num[i]=='4')
		{
			ans+="4";
		}
	}
	for(int i=0;i<=n+1;i++)
	{
		if(num[i]=='3')
		{
			ans+="3";
		}
	}
	for(int i=0;i<=n+1;i++)
	{
		if(num[i]=='2')
		{
			ans+="2";
		}
	}
	for(int i=0;i<=n+1;i++)
	{
		if(num[i]=='1')
		{
			ans+="1";
		}
	}
	for(int i=0;i<=n+1;i++)
	{
		if(num[i]=='0')
		{
			ans+="0";
		}
	}
	cout<<ans;
	return 0;
}