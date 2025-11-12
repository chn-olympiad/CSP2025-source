#include<bits/stdc++.h>
using namespace std;
int zui[500005],sum[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a;
	cin>>n>>k;
	cin>>a;
	sum[1]=a;
	for(int i=2;i<=n;i++)
	{
		cin>>a;
		sum[i]=sum[i-1]^a;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int o=sum[i-1]^sum[j];
			if(o==k)
			{
				zui[j]=max(zui[j],zui[i-1]+1);
			}
			else
			{
				zui[j]=max(zui[j],zui[i-1]);
			}
		}
	}
	cout<<zui[n];
	return 0;
}
