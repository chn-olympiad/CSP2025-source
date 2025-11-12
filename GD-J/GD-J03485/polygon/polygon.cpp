#include <bits/stdc++.h>
using namespace std;
int n,a[5002],s,k,b[5002];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s+=a[i];
		k=max(k,a[i]);
		b[i]=s;
	}
	sort(a+1,a+n+1);
	if(n<3)
	{
		cout<<"0";
	}
	else if(n==3)
	{
		if(k<s-k)
		{
			cout<<"1";
		}
	}
	else
	{
		int ans=0;
		for(int i=n;i>=1;i++)
		{
			s-=a[i];
			if(a[i]<s)
			{
				ans=(ans+1)%998244353;
			}
		}
		cout<<ans;
	}
	return 0;
}
