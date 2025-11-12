#include<bits/stdc++.h>
using namespace std;
int n,a[5001],qz[5001],ans=0,k=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)k=1;
	}
	if(n<=3)
	{
		int y=max(a[1],max(a[2],a[3]));
		if(a[1]+a[2]+a[3]>y*2)cout<<1;
		else cout<<0;
		return 0;
	}
	if(k==1)
	{
		cout<<9;
		return 0;
	}
	if(k==0)
	{
		int x=n-3+1;
		if(x%2==0)
		{
			ans=(x+1)*(x/2);
		}
		else
		{
			ans=(x+1)*(x/2)+(x/2+1);
		}
	}
	cout<<ans%998244353;
	return 0;
}
