#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],f[500005],sum[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	cin>>a[1];
	sum[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=(sum[i-1]^a[i]);
	}
	if(sum[1]==k)f[1]=1;
	for(int i=2;i<=n;i++)
	{
		f[i]=f[i-1];
		if(sum[i]==k)
		{
			f[i]=max(f[i],1);
		}
		int ans=f[i];
		for(int j=i-1;j>=1;j--)
		{
			if(f[j]<f[i])
			{
				break;
			}
			for(int w=j+1;w<=i;w++)
			{
				if((sum[i]^sum[j])==k)
				{
					f[i]=max(f[i],f[j]+1);
				}
			}
			if(ans>f[i])
			{
				break;
			}
		}
	}
	cout<<f[n];
	return 0;
}