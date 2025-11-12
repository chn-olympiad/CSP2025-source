#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100005][5],ans;
int cnt[5];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n),ans=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) cnt[1]++,ans+=a[i][1];
			else
			{
				if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) cnt[2]++,ans+=a[i][2];
				else
				{
					if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]) cnt[3]++,ans+=a[i][3];
				}
			}
		}
		for(int i=1;i<=3;i++)
		{
			if(cnt[i]>n/2)
			{
				priority_queue<int,vector<int>,greater<int>> q;
				for(int j=1;j<=n;j++)
				{
					if(i==1&&a[j][1]>=a[j][2]&&a[j][1]>=a[j][3])
						q.push(min(a[j][1]-a[j][2],a[j][1]-a[j][3]));
					if(i==2&&a[j][2]>=a[j][1]&&a[j][2]>=a[j][3])
						q.push(min(a[j][2]-a[j][1],a[j][2]-a[j][3]));
					if(i==3&&a[j][3]>=a[j][1]&&a[j][3]>=a[j][2])
						q.push(min(a[j][3]-a[j][1],a[j][3]-a[j][2]));
				}
				while(cnt[i]>n/2) ans-=q.top(),q.pop(),cnt[i]--;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
