#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],f[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int ann;
			if(i==j) ann=a[i];
			else
			{
				ann=a[i]^a[i+1];
				for(int k=i+2;k<=j;k++)
				{
					ann=ann^a[k];
				}
			}
			if(ann==k)
			{
				f[j]=max(f[i-1]+1,f[j]);
			}
			else
			{
				f[j]=max(f[i-1],f[j]);
			}
		}
	}
	cout<<f[n];
	return 0;
}