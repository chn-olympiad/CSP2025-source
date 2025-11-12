#include<bits/stdc++.h>
using namespace std;
int n,a[50010],k,ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==3)
	{
		int w=max(max(a[1],a[2]),a[3]);
		if(a[1]+a[2]+a[3]>2*w)cout<<1;
		else cout<<0;
	}
	else
	{
		for(int i=3;i<=n;i++)//C(n,i)
		{
			k=1;
			for(int j=n;j>=n-i+1;j--)
			{
				k*=j;
			}
			for(int j=i;j>=1;j--)
			{
				k/=j;
			}
			ans+=k;
		}
		cout<<ans;
	}
	return 0;
}
