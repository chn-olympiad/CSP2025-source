#include<bits/stdc++.h>
using namespace std;
long long n,k,ans,sum[1000005],maxx;
long long a[1000005],check[2000005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]^a[i];
		maxx=max(maxx,sum[i]);
	}
	check[0]=1;
	for(int i=1;i<=n;i++)
	{
//		cout<<sum[i]<<" ";
//		cout<<(k^sum[i]);
//		cout<<"\n";
		if(check[k^sum[i]]==1)
		{
			ans++;
			memset(check,0,maxx*16);
			check[sum[i]]=1;
		}
		else
		{
			check[sum[i]]=1;
		}
	}
	printf("%lld",ans);
	return 0;
}

