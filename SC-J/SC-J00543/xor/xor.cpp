#include <bits/stdc++.h>
using namespace std;
int n,k,a[500010],sum[500010],cnt,s=1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum[i]=(sum[i-1]^a[i]);
		for(int j=s;j<=i;j++)
		{
			if((sum[j-1]^sum[i])==k)
			{
				s=i+1;
				cnt++;
				break;
			}
		}
	}
	printf("%d",cnt);
	return 0;
}