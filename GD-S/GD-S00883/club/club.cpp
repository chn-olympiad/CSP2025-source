#include<bits/stdc++.h>
using namespace std;
const int N=1000009;
long long T,n,a[N][3];
vector<long long> cnt[3];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		long long ans=0;
		cnt[0].clear(),cnt[1].clear(),cnt[2].clear();
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
			if(a[i][0]>a[i][1]&&a[i][0]>a[i][2])
				cnt[0].push_back(a[i][0]-max(a[i][1],a[i][2]));
			else if(a[i][1]>a[i][0]&&a[i][1]>a[i][2])
				cnt[1].push_back(a[i][1]-max(a[i][0],a[i][2]));
			else cnt[2].push_back(a[i][2]-max(a[i][0],a[i][1]));
			ans=ans+max(a[i][0],max(a[i][1],a[i][2]));
		}
		int jl=0;
		for(int j=1;j<3;j++)
			if(cnt[j].size()>cnt[jl].size())
				jl=j;
		if(cnt[jl].size()>n/2)
		{
			sort(cnt[jl].begin(),cnt[jl].end());
			int u=cnt[jl].size(),h=0;
			while(u>n/2) u--,ans-=cnt[jl][h],h++;
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
