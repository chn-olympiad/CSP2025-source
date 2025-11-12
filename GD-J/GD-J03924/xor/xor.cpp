#include<bits/stdc++.h>
#define int long long
using namespace std;
long long n,k,g,a[500005],ans;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int l=a[i];
		if(l==k)
		{
			ans++;
			g=i;
			continue;
		}
		for(int j=i-1;j>g;j--)
		{
			l=l^a[j];
			if(l==k)
			{
				ans++;
				g=i;
				break;
			}
		}
	}
	printf("%lld",ans);
}
