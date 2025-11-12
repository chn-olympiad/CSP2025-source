#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005][3],cnt[100005];
vector<long long>d[3];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		cnt[0]=cnt[1]=cnt[2]=0;
		d[0].clear();d[1].clear();d[2].clear();
		scanf("%lld",&n);long long ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
			long long mx=max(a[i][0],max(a[i][1],a[i][2]));
			if(a[i][0]==mx)
			{
				cnt[0]++;d[0].push_back(a[i][0]-max(a[i][1],a[i][2]));
			}
			else if(a[i][1]==mx)
			{
				cnt[1]++;d[1].push_back(a[i][1]-max(a[i][0],a[i][2]));
			}
			else
			{
				cnt[2]++;d[2].push_back(a[i][2]-max(a[i][1],a[i][0]));
			}
			ans+=mx;
		}
		sort(d[0].begin(),d[0].end());
		sort(d[1].begin(),d[1].end());
		sort(d[2].begin(),d[2].end());
		
		if(cnt[0]>n/2)
		{
			for(int v:d[0])
			{
				ans-=v;cnt[0]--;
				if(cnt[0]<=n/2) break;
			}
		}
		else if(cnt[1]>n/2)
		{
			for(int v:d[1])
			{
				ans-=v;cnt[1]--;
				if(cnt[1]<=n/2) break;
			}
			
		}
		else if(cnt[2]>n/2)
		{
			for(int v:d[2])
			{
				ans-=v;cnt[2]--;
				if(cnt[2]<=n/2) break;
			}
		}
		printf("%lld\n",ans);
		
	}
	return 0;
}
