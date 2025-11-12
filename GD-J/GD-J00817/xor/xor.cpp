#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int sum=0,n,k,a[10000],l,r;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i]|a[j]==k)
			{
				sum++;
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		if(a[k]==k)
		{
			sum++;
		}
	}
	cout<<k;
	return 0;
}
