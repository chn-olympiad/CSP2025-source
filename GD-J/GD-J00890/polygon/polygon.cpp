#include <bits/stdc++.h>
using namespace std;
int a[5012];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,m=0,sum=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		m=max(m,a[i]);
		sum+=a[i];
	}
	if(n==3)
	{	
		if(sum>2*m)
		{
			ans=1;
		}
	}
	else
	{
		for(int i=3;i<n-1;i++)
		{
			int site=1;
			for(int j=n;j>i;j--)
				site*=j;
			ans+=site;
		}
		ans+=n;
		ans++;
	}
	cout<<ans;
	return 0;
}
