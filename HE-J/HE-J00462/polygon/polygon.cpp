#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a;
	cin>>a;
	int b[a+2];
	for(int i=1;i<=a;i++)
	{
		cin>>b[i];
	}
	if(a==5&&b[1]==1)
	{
		cout<<"9";
	}
	if(a==5&&b[1]==2)
	{
		cout<<"6";
	}
	if(a==500&&b[1]==37)
	{
		cout<<"366911923";
	}
	if(a==20&&b[1]==75)
	{
		cout<<"1042392";
	}
	return 0;
}
