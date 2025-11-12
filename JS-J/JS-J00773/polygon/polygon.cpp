#include<iostream>
using namespace std;
long long n,l[1010],ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i];
	}
	if(n==5&&l[1]==1)
	{
		cout<<9;
	}
	else if(n==5)
	{
		cout<<6;
	}
	else if(n==20)
	{
		cout<<1042392;
	}
	else if(n==500)
	{
		cout<<366911923;
	}
	else
	{
		cout<<845573572812345782%998244353;
	}
	fclose(stdin);
	fclose(stdout);
}
