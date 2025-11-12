#include <bits/stdc++.h>
using namespace std;
long long n,a,c0=0,c1=0,c2 =0,c3=0,c4=0,c5=0,c6=0,c7=0,c8=0,c9=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	n = a;
	while(a)
	{
		n = a % 10;
		a /= 10;
		if(n == 0)
		{
			if(c0>2)
			{
				continue;
			}
			c0++;
		}
		if(n == 1)
		{
			if(c1>2)
			{
				continue;
			}
			c1++;
		}if(n == 2)
		{
			if(c2>2)
			{
				continue;
			}
			c2++;
		}if(n == 3)
		{
			if(c3>2)
			{
				continue;
			}
			c3++;
		}if(n == 4)
		{
			if(c4>2)
			{
				continue;
			}
			c4++;
		}if(n == 5)
		{
			if(c5>2)
			{
				continue;
			}
			c5++;
		}if(n == 6)
		{
			if(c6>2)
			{
				continue;
			}
			c6++;
		}
		if(n == 7)
		{
			if(c7>2)
			{
				continue;
			}
			c7++;
		}if(n == 8)
		{
			if(c8>2)
			{
				continue;
			}
			c8++;
		}if(n == 9)
		{
			if(c9>2)
			{
				continue;
			}
			c9++;
		}
	}
	for(int i = 1;i<=c9;i++)
	{
		cout<<"9";
	}
	for(int i = 1;i<=c8;i++)
	{
		cout<<"8";
	}
	for(int i = 1;i<=c7;i++)
	{
		cout<<"7";
	}
	for(int i = 1;i<=c6;i++)
	{
		cout<<"6";
	}
	for(int i = 1;i<=c5;i++)
	{
		cout<<"5";
	}
	for(int i = 1;i<=c4;i++)
	{
		cout<<"4";
	}
	for(int i = 1;i<=c3;i++)
	{
		cout<<"3";
	}
	for(int i = 1;i<=c2;i++)
	{
		cout<<"2";
	}
	for(int i = 1;i<=c1;i++)
	{
		cout<<"1";
	}
	for(int i = 1;i<=c0;i++)
	{
		cout<<"0";
	}
	
	return 0;
}
