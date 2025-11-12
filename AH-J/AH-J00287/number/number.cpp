#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int b=a.size();
	int u9=0,u8=0,u7=0,u6=0,u5=0,u4=0,u3=0,u2=0,u1=0,u0=0;
	for(int i=0;i<b;i++)
	{
		if(a[i]=='9')
		{
			u9++;
		}
		else if(a[i]=='8')
		{
			u8++;
		}
		else if(a[i]=='7')
		{
			u7++;
		}
		else if(a[i]=='6')
		{
			u6++;
		}
		else if(a[i]=='5')
		{
			u5++;
		}
		else if(a[i]=='4')
		{
			u4++;
		}
		else if(a[i]=='3')
		{
			u3++;
		}
		else if(a[i]=='2')
		{
			u2++;
		}
		else if(a[i]=='1')
		{
			u1++;
		}
		else if(a[i]=='0')
		{
			u0++;
		}
	}
	for(int i=1;i<=u9;i++)
	{
		cout<<9;
	}
	for(int i=1;i<=u8;i++)
	{
		cout<<8;
	}
	for(int i=1;i<=u7;i++)
	{
		cout<<7;
	}
	for(int i=1;i<=u6;i++)
	{
		cout<<6;
	}
	for(int i=1;i<=u5;i++)
	{
		cout<<5;
	}
	for(int i=1;i<=u4;i++)
	{
		cout<<4;
	}
	for(int i=1;i<=u3;i++)
	{
		cout<<3;
	}
	for(int i=1;i<=u2;i++)
	{
		cout<<2;
	}
	for(int i=1;i<=u1;i++)
	{
		cout<<1;
	}
	for(int i=1;i<=u0;i++)
	{
		cout<<0;
	}
	return 0;
}
