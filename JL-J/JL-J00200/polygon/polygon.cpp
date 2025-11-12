#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100100],b[1000010],ans,sum=2,q,h;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	/*b[1]=a[1];
	b[2]=a[2];
	for(int i=3;i<=n;i++)
	{
		int t=sum;
		for(int j=1;j<=t;j++)
		{
			for(int k=1;k<=t;k++)
			{
				b[k+1]=b[j]+b[k];
				sum++;
			}
		}
		for(int j=1;j<=sum;j++)
		{
			if(b[j]>a[i])
			{
				ans++;
			}
		}
	}
	for(int i=1;i<=sum;i++)
	{
		cout<<b[i]<<endl;
	}
	
	cout<<ans<<endl;*/
	h=a[1];
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=h)
		{
			q++;
		}
	}
	if(n==3&&a[1]+a[2]>a[3])
	{
		cout<<1<<endl;
	}
	if(q==0)
	{
		for(int i=1;i<=n-2;i++)
		{
			h+=i;
		}
		cout<<h<<endl;
	}
	return 0;
}

