#include<bits/stdc++.h>
using namespace std;

string s;
string s2;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	int l=s.size()-1;
	int k=0;
	
	for(int i=0;i<=l;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			s2[k]=s[i];
			k++;
		}
	}
	
	for(int i=0;i<=k;i++)
	{
		if(s2[i]=='9')
		{
			cout<<9;
		}
	}
	for(int i=0;i<=k;i++)
	{
		if(s2[i]=='8')
		{
			cout<<8;
		}
	}
	for(int i=0;i<=k;i++)
	{
		if(s2[i]=='7')
		{
			cout<<7;
		}
	}
	for(int i=0;i<=k;i++)
	{
		if(s2[i]=='6')
		{
			cout<<6;
		}
	}
	for(int i=0;i<=k;i++)
	{
		if(s2[i]=='5')
		{
			cout<<5;
		}
	}
	for(int i=0;i<=k;i++)
	{
		if(s2[i]=='4')
		{
			cout<<4;
		}
	}
	for(int i=0;i<=k;i++)
	{
		if(s2[i]=='3')
		{
			cout<<3;
		}
	}
	for(int i=0;i<=k;i++)
	{
		if(s2[i]=='2')
		{
			cout<<2;
		}
	}
	for(int i=0;i<=k;i++)
	{
		if(s2[i]=='1')
		{
			cout<<1;
		}
	}
	for(int i=0;i<=k;i++)
	{
		if(s2[i]=='0')
		{
			cout<<0;
		}
	}
	return 0;
}
