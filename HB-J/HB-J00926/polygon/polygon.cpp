#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<3)
	{
		cout<<"0";
	}
	if(n==3)
	{
		int ans;
		for(int i=1;i<=3;i++)
		{
			if(a[i]>=ans)
			{
				ans=a[i];
			}
		}
		if((a[1]+a[2]+a[3])>ans*2)
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}
	return 0;
}
