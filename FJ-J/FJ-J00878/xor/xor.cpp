#include <bits/stdc++.h>
using namespace std;
int n,k,a[50000005],sum,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int l=1,r=1;
	
	for (;l<=n;l=r+1)
	{
		sum=a[l];
		for (;r<=n;r++)
		{
			if(sum==k)
			{
				ans++;
				continue;
			}
			sum^=a[r];
		}
	}
	cout<<ans;
	return 0;
}
