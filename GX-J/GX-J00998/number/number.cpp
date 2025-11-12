#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a,s;
	cin>>a;
	if(a<10)
	{
		cout<<a;
	}
	else if(a>=10 && a<100)
	{
		if(a%10>a/10)
		{
			s=a%10*10;
			a=a/10+s;
		}
		cout<<a;
	}
	else if(a>=100 && a<1000)
	{
		if(a%10>a/100)
		{
			a=a/100+a%100*10;
		}
		if(a/10%10<a%10)
		{
			a=a/100*100+a%10*10+a/10%10;
		}
		if(a/10%10>a/100)
		{
			a=a/10%10*100+a/100*10+a%10;
		}
		cout<<a;
	}
	return 0;
}
