//100
#include <bits/stdc++.h>
using namespace std;
int a[100005][4];
struct node
{
	int w,id,id2;
	bool operator < (const node x) const
	{
		if(w==x.w) return id2<x.id2;
		return w<x.w;
	}
};
node chasum[5000005];
int cnt2[100005];
int cntt[100005];
void clear()
{
	memset(cnt2,0,sizeof(cnt2));
	memset(cntt,0,sizeof(cntt));
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		int ans = 0,cnt = 0;
		int qwq1 = 0,qwq2 = 0,qwq3 = 0;
		for(int i=1;i<=n;i++)
		{
			int maxx = max(a[i][1],max(a[i][2],a[i][3]));
			ans+=maxx;
			int minn = min(a[i][1],min(a[i][2],a[i][3]));
			if(maxx==a[i][1])
			{
				qwq1++;
				cnt2[i] = 1;
				if(minn==a[i][2])
				{
					chasum[++cnt] = {a[i][1]-minn,2,i};
					chasum[++cnt] = {a[i][1]-a[i][3],3,i};
				}
				else
				{
					chasum[++cnt] = {a[i][1]-minn,3,i};
					chasum[++cnt] = {a[i][1]-a[i][2],2,i};
				}
			}
			else if(maxx==a[i][2])
			{
				qwq2++;
				cnt2[i] = 2;
				if(minn==a[i][3])
				{
					chasum[++cnt] = {a[i][2]-minn,3,i};
					chasum[++cnt] = {a[i][2]-a[i][1],1,i};
				}
				else
				{
					chasum[++cnt] = {a[i][2]-minn,1,i};
					chasum[++cnt] = {a[i][2]-a[i][3],3,i};
				}
			}
			else if(maxx==a[i][3])
			{
				qwq3++;
				cnt2[i] = 3;
				if(minn==a[i][2])
				{
					chasum[++cnt] = {a[i][3]-minn,2,i};
					chasum[++cnt] = {a[i][3]-a[i][1],1,i};
				}
				else
				{
					chasum[++cnt] = {a[i][3]-minn,1,i};
					chasum[++cnt] = {a[i][3]-a[i][2],2,i};
				}
			}
		}
		sort(chasum+1,chasum+cnt+1);
		if(qwq1>n/2)
		{
			for(int i=1;i<=cnt;i++)
			{
				if(cnt2[chasum[i].id2]==1&&cntt[chasum[i].id2]==0)
				{
					cntt[chasum[i].id2]++;
					ans-=chasum[i].w;
					cnt2[chasum[i].id2] = chasum[i].id;
					qwq1--;
				
					if(qwq1<=n/2) break;
				}
			}
			printf("%d\n",ans);
		}
		else if(qwq2>n/2)
		{
			for(int i=1;i<=cnt;i++)
			{
				if(cnt2[chasum[i].id2]==2&&cntt[chasum[i].id2]==0)
				{
					cntt[chasum[i].id2]++;
					ans-=chasum[i].w;
					cnt2[chasum[i].id2] = chasum[i].id;
					qwq2--;
					if(chasum[i].id==1) qwq1++;
					else qwq3++;
					if(qwq2<=n/2) break;
				}
			}
			printf("%d\n",ans);
		}
		else if(qwq3>n/2)
		{
			for(int i=1;i<=cnt;i++)
			{
				if(cnt2[chasum[i].id2]==3&&cntt[chasum[i].id2]==0)
				{
					cntt[chasum[i].id2]++;
					ans-=chasum[i].w;
					cnt2[chasum[i].id2] = chasum[i].id;
					qwq3--;
					if(chasum[i].id==2) qwq2++;
					else qwq1++;
					if(qwq3<=n/2) break;
				}
			}
			printf("%d\n",ans);
		}
		else
		{
			printf("%d\n",ans);
		}
		clear();
	}
}
