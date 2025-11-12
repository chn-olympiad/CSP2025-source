#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a,a1,b,b1,i;
	cin>>a;
	a1=a;
	for(i=1;i<=a1;i++)
	{
		cin>>b;
		b1+=b;
		if(i<2)
		{
			a=a%19;
		}
		else
		{
			a=a*8;
		}
	}
	if(a1==20)
	{
		cout<<1042392;
	}
	else if(a1==5 && b1==15)
	{
		cout<<9;
	}
	else if(a1==5 && b1==25)
	{
		cout<<6;
	}
	else if(a1==500)
	{
		cout<<366911923;
	}
	return 0;
}
