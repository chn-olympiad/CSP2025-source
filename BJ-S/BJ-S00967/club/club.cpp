#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][3],mxid[N],cnt[3];
pair<int,int> dlt[N];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int _;
	scanf("%d",&_);
	while (_--)
	{
		int n,ans=0;
		scanf("%d",&n);
		for (int i=0;i<3;i++)
			cnt[i]=0;
		int mx;
		for (int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			mx=max({a[i][0],a[i][1],a[i][2]});
			ans+=mx;
			dlt[i]=make_pair(mx-(a[i][0]+a[i][1]+a[i][2]-mx-min({a[i][0],a[i][1],a[i][2]})),i);
			for (int j=0;j<3;j++)
				if (a[i][j]>a[i][mxid[i]])
					mxid[i]=j;
			cnt[mxid[i]]++;
		}
		mx=max({cnt[0],cnt[1],cnt[2]})-n/2;
		if (mx>0)
		{
			sort(dlt+1,dlt+n+1);
			int p=0;
			for (int i=1;i<3;i++)
				if (cnt[i]>cnt[p])
					p=i;
			for (int i=1,j=0;i<=n&&j<mx;i++)
			{
				if (mxid[dlt[i].second]!=p)
					continue;
				ans-=dlt[i].first;
				j++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
