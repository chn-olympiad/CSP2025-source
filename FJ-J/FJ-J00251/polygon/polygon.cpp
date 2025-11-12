#include<bits/stdc++.h>
using namespace std;
int p[6000];
int main()	
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
	}
	sort(p,p+n);
	if(p[n-1]==1)
	{
		for(int i=n-2;i>0;i--)
		{
			for(int j=1;j<=i;j++)
			{
				ans+=j;
			}
			ans=ans%998244353;
		}
		cout<<ans;
		return 0;
	}
	else if(n==3)
	{
		if(p[0]+p[1]>p[2])
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
		return 0;
	}
	return 0;
} 
