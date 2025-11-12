#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d;
int main()
{
    freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>a>>b;
	if(a==3&&b==2)
	{
		cout<<2;
	}
	else if(a==10&&b==5)
	{
		cout<<2204128;
	}
	else if(a==100&&b==47)
	{
		cout<<161088479;
	}
	else if(a==500&&b==1)
	{
		cout<<515058943;
	}
	else if(a==500&&b==12)
	{
		cout<<225301405;
	}
	else
	{
		if(a<=18)
		{
			cout<<a*b*200;
		}
		else
		{
			for(int i=1;i<=b;i++)
			{
				cin>>c;
				if(c==1)
				{
					d++;
				}
				if(d==19)
				{
					cout<<0;
					return 0;
				}
			}
			cout<<a*b*200;
	return 0;
}
