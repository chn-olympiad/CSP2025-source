#include<bits/stdc++.h>
using namespace std;
int a[500001],maxn;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int sum=a[i];
			if(i==j&&sum==k)
			{
				maxn++;
				continue;
			}
			for(int k=i+1;k<=j;k++)
			{
				sum^=a[k];
			}
			if(sum==k)
			{
				maxn++;
			}
		}
	}
	cout<<maxn;
	return 0;
}
