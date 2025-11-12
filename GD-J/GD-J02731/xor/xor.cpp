#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],sum[500010],f[1100010],la=0,ans=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=(sum[i-1]^a[i]);
	}
	f[0]=1;
	for(long long i=1;i<=n;i++)
	{
		if(f[sum[i]^k])
		{
			ans++;
			while(la<i)
			{
				f[sum[la]]--;
				la++;
			}
		}
		f[sum[i]]++;
	}
	cout<<ans;
	return 0;
}
