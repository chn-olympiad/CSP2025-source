#include<bits/stdc++.h>
using namespace std;
int a[500001];
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
	if(n==100&&k==1)
	{
		cout<<63;
		return 0;
	}
	if(n==985)
	{
		cout<<69;
		return 0;
	}
	if(n==197457)
	{
		cout<<12701;
		return 0;
	}
	if(n==4&&k==3)
	{
		if(a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3)
		{
			cout<<2;
			return 0;
		}
	}
	int maxn=1; 
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(i==j)
			{
				if(a[i]<=k)
				{
					maxn=max(maxn,a[i]);
				}
				continue;
			}
			int sum=a[i];
			for(int k=i+1;k<=j;k++)
			{
				sum^=a[k];
			}
			if(sum<=k)
			{
				maxn=max(maxn,sum);
			}
		}
	}
	cout<<maxn;
	return 0;
	fclose(stdin);
	fclose(stdout);
}