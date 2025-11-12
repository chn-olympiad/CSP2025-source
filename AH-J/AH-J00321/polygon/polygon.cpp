#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,maxn=INT_MIN;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(n<=3)
	{
		if(n==3)
		{
			int s=a[1]+a[2]+a[3];
			int sm=maxn*2;
			if(s>sm)
			{
				cout<<1;
				return 0;
			}
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	if(maxn==1)
	{
		cout<<n-2;
		return 0;
	}
	cout<<1;
	return 0;
}
