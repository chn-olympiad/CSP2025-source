#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int mmax=0;
	for(int i=0;i<n;i++)
	{
		if(mmax<a[i])
		{
			mmax=a[i];
		}
	}
	if(a[0]+a[1]+a[2]>2*mmax)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
