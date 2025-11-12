#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[10000];
	cin>>n;
	for(int i =1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<3)
	{
		cout<<0;
	}
	if(n == 3)
	{
		int m = 0,sum = 0;
		for(int i =1;i<=n;i++)
		{
			if(a[i]>m)
			{
				sum+=a[i];
				m = a[i];
			}
		}
		if(sum>m*2)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	return 0;
}
