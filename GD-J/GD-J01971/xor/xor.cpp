#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int ans=0;
	if(k==1)
	{
		for(int i=1;i<=n;i++)
			if(a[i]==1)
				ans++;
		printf("%d",ans);
		return 0;
	}
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
				ans++;
			if(a[i]==1&&a[i+1]==1&&i+1<=n)
			{
				ans++;
				i++;
			}
		}
		printf("%d",ans);
		return 0;
	}
	else
	{
		int x=0;
		for(int i=1;i<=n;i++)
		{
			int y=0;
			for(int t=i;t>x;t--)
			{
				y^=a[t];
				if(y==k)
				{
					ans++;
					x=i;
					break;
				}
			}
		}
		printf("%d",ans);
		return 0;
	}
	return 0;
}
