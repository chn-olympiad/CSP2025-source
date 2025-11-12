#include <bits/stdc++.h>
using namespace std;
int n,k,f[500001],a[500001],sum[500001],maxn[5000001],ans;//f[i]表示在前i个数里的最大区间
bool check[5000001]; 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.in","w",stdout);
	cin>>n>>k;
	check[0]=1;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for (int i=1;i<=n;i++)
	{
		int an=k^sum[i];
		f[i]=f[i-1];
		if(check[an])
		{
			f[i]=max(f[i],maxn[an]+1);
		}
		maxn[sum[i]]=max(maxn[sum[i]],f[i]);
		check[sum[i]]=1;
		ans=max(f[i],ans);
	}
	cout<<ans;
	return 0;
}
