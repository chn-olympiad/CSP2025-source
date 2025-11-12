#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,a[5001],ans=0;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	if(n==3 && a[2]+a[3]>a[1])
			ans=1;
	if(n==4)
	{
		if(a[3]+a[4]>a[1])
			ans=3;
		else
		{
			if(a[2]+a[4]>a[1])
				ans=2;
			else
			{
				if(a[2]+a[3]>a[1] && a[3]+a[4]>a[2])
					ans=2;
				else
					ans=1;
			}
		}
		if(a[1]*2<a[1]+a[2]+a[3]+a[4])
			ans++;
	}
	cout<<ans;
	return 0;
}
