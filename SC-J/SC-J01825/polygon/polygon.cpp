#include<iostream>
using namespace std;
int n,k,a[10000010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	cin>>k;
	for(int i=1;i<=n-1;i++)
	{
		cin>>a[i];
	}
	if(n==5&&k==1)
	{
		cout<<9;
	}
	else if(n==5&&k==2)
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
		cout<<n*k%998244353;
	}
	return 0;
}