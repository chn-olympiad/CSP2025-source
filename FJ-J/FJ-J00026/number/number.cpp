#include <bits/stdc++.h>
using namespace std;
int aa,ss,dd,aaa,sss,ddd,aaaa,ssss,dddd,z;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.length();i++)
	{
		if (a[i]>='0' && a[i]<='9')
		{
			if (a[i]=='9')
			{
				aa++;
			}
			if (a[i]=='8')
			{
				ss++;
			}
			if (a[i]=='7')
			{
				dd++;
			}
			if (a[i]=='6')
			{
				aaa++;
			}
			if (a[i]=='5')
			{
				sss++;
			}
			if (a[i]=='4')
			{
				ddd++;
			}
			if (a[i]=='3')
			{
				aaaa++;
			}
			if (a[i]=='2')
			{
				ssss++;
			}
			if (a[i]=='1')
			{
				dddd++;
			}
			if (a[i]=='0')
			{
				z++;
			}
		}
		
	}
	for (int i=0;i<aa;i++)
	{
		cout<<9;
	}
	for (int i=0;i<ss;i++)
	{
		cout<<8;
	}
	for (int i=0;i<dd;i++)
	{
		cout<<7;
	}
	for (int i=0;i<aaa;i++)
	{
		cout<<6;
	}
	for (int i=0;i<sss;i++)
	{
		cout<<5;
	}
	for (int i=0;i<ddd;i++)
	{
		cout<<4;
	}
	for (int i=0;i<aaaa;i++)
	{
		cout<<3;
	}
	for (int i=0;i<ssss;i++)
	{
		cout<<2;
	}
	for (int i=0;i<dddd;i++)
	{
		cout<<1;
	}
	for (int i=0;i<z;i++)
	{
		cout<<0;
	}
	return 0;
}
