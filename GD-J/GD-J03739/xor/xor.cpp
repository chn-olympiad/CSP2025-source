#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans;
bool vis[500005];
bool check(int l,int r)
{
	int sum=a[l];
	for (int i=l+1;i<=r;i++)
		sum^=a[i];
	return sum==k;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		if (vis[i])
			continue;
		int sum=a[i],j;
		vis[i]=true;
		if (sum==k)
		{
			ans++;
			continue;
		}
		for (j=i+1;j<=n;j++)
		{
			sum^=a[j];
			vis[j]=true;
			if (sum==k)
			{
				ans++;
				break;	
			}
		}
		if (sum!=k)
			for (int k=i;k<=j;k++)
				vis[k]=false;
	}
	printf("%d",ans);
	return 0;
}
