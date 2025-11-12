//30
#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	int maxx = 0;
	int cnt = 0;
	int cnt2 = 0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==1) cnt++;
		else if(a[i]==0) cnt2++;
	}
	if(k==0&&cnt==n)
	{
		printf("%d",n/2);
	}
	else if(k==0&&cnt+cnt2==n)
	{
		int qwq = 0,ans = 0;
		bool flag = 0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				if(flag==1) flag = 0;
				qwq = 0;
				ans++;
			}
			else
			{
				if(flag==0)
				{
					flag = 1;
					qwq++;
				}
				else
				{
					qwq++;
					if(qwq==2)
					{
						qwq = 0;
						ans++;
					}
				}
			}
		}
		printf("%d",ans);
	}
	else if(k==1&&cnt+cnt2==n)
	{
		int ans = 0;
		for(int i=1;i<=n;i++)
			if(a[i]==1)
					ans++;
		printf("%d",ans);
	}
	return 0;
}