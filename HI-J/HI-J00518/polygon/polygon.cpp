#include <iostream>
using namespace std;
int n,a[1005],s,t;
int main()
{
	freopen("polygon.in","r","stdin");
	freopen("polygon.out","w","stdout"); 
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=2;i<=n;i++)
	{
		if (a[i]>a[i-1])
		{
			t=a[i];
			a[i]=a[i-1];
			a[i-1]=t;
		}
	}
	for (int i=3;i<=n;i++)
	{
		if (a[i]+a[i-1]+a[i-2]>a[i]*2)
		{
			s++;
		}
	}
	for (int i=4;i<=n;i++)
	{
		if (a[i]+a[i-1]+a[i-2]+a[i-3]>a[i]*2)
		{
			s++;
		}
	}
	for (int i=5;i<=n;i++)
	{
		if (a[i]+a[i-1]+a[i-2]+a[i-3]+a[i-4]>a[i]*2)
		{
			s++;
		}
	}
	cout<<s+2;
	return 0;
}
