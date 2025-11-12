#include<bits/stdc++.h>
using namespace std;
int a[10000],n,k,m,sum,ans,z;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if (j<z)
			{
				continue;
			}
			sum=a[i];
			for (int x=i+1;x<=j;x++)
			{
				sum^=a[x];
			}
			if (sum==k)
			{
				ans++;
				z=j;
			}
		}
	}
	cout<<ans;
	return 0;
}
