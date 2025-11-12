#include<bits/stdc++.h>
using namespace std;
int a[500005],n,k;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int sum=0;
		for(int j=i;j<=n;j++)
		{
			sum=sum^a[j];
			if(sum==k)
			{
				i=j;
				ans++;
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
