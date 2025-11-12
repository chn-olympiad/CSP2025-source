#include<bits/stdc++.h>
using namespace std;
int n,k;
int ans;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				int y=0;
				for(int j=i;j<=n;j++)
				{
					if(a[j]==0)
					{
						y++;
					}
					else
					{
						break;
					}
				}
				ans=max(ans,y);
			}
		}
	}
	else if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				ans++;
			}
		}
	}
	printf("ans");
	return 0;
}
