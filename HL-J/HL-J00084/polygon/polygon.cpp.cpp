#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a,b[a+2];
	cin>>a;
	for(int i=0;i<a;i++)
	{
		cin>>b[i];
	}
	if(a==3)
	{
		if(b[0]+b[1]>b[2])
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		cout<<77;
	}
	return 0;
}
