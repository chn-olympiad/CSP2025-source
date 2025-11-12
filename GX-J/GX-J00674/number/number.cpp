#include <iostream>
using namespace std;
string a;
int b,c[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout) ;
	cin>>a;
	b=a.length();
	for(int i=0;i<b;i++)//=8
	{
		c[i]=a[i];
	
	for(int i=0;i<b;i++)//=9
	{
		if(c[i]==57)
		{
			cout<<9;
			
		}
	}
	for(int i=0;i<b;i++)//=8
	{
		if(c[i]==56)
		{
			cout<<8;
		}
	}
	for(int i=0;i<b;i++)//=7
	{
		if(c[i]==55)
		{
			cout<<7;
		}
	}
	for(int i=0;i<b;i++)//=6
	{
		if(c[i]==54)
		{
			cout<<6;
		}
	}
	for(int i=0;i<b;i++)//=5
	{
		if(c[i]==53)
		{
			cout<<5;
		}
	}
	for(int i=0;i<b;i++)//=4
	{
		if(c[i]==52)
		{
			cout<<4;
		}
	}
	for(int i=0;i<b;i++)//=3
	{
		if(c[i]==51)
		{
			cout<<3;
		}
	}
	for(int i=0;i<b;i++)//=2
	{
		if(c[i]==50)
		{
			cout<<2;
		}
	}
	for(int i=0;i<b;i++)//=1
	{
		if(c[i]==49)
		{
			cout<<1;
		}
	}
	for(int i=0;i<b;i++)//=0
	{
		if(c[i]==48)
		{
			cout<<0;
		}
	}
	return 0;
}
