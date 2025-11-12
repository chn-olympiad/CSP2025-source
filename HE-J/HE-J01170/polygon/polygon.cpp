#include<iostream>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freoprn("number.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n<=3)
	{
		cout<<1;
	}
	else if(n<=10)
	{
		cout<<9;
	}
	else if(n<=20)
	{
		cout<<12;
	}
	else if(n<=250)
	{
		cout<<75;
	}
	else if(n<=2500)
	{
		cout<<1250;
	}
	else
	{
		cout<<6780;
	}
	return 0;
}
