#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> >q[3];
int cnt[3];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,n2,ans=0;
		scanf("%d",&n);
		n2=n>>1;
		for(int i=1;i<=n;i++)
		{
			int a[3];
			scanf("%d%d%d",a+0,a+1,a+2);
			int mxn=0,mnd=1e9;
			for(int j=1;j<3;j++)
			{
				if(a[mxn]<a[j])
					mxn=j;
			}
			cnt[mxn]++;
			ans+=a[mxn];
			for(int j=0;j<3;j++)
			{
				if(mxn==j)
					continue;
				mnd=min(mnd,a[mxn]-a[j]);
			}
			q[mxn].push(mnd);
		}
		for(int i=0;i<3;i++)
		{
			while(cnt[i]>n2)
			{
				cnt[i]--;
				ans-=q[i].top();
				q[i].pop();
			}
			while(q[i].size())
				q[i].pop();
			cnt[i]=0;
		}
		printf("%d\n",ans);
	}
	return 0;
}
