#include<bits/stdc++.h>
using namespace std;
long long n,a[100010][4],ans,cha[100010];
vector <long long> who[4];
bool cmp(long long xxx,long long yyy)
{
	return cha[xxx]<cha[yyy];
}
void solve()
{
	ans=0;
	scanf("%lld",&n);
	who[1].clear(),who[2].clear(),who[3].clear();
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		ans+=max({a[i][1],a[i][2],a[i][3]});
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
		{
			who[1].emplace_back(i);
			cha[i]=a[i][1]-max(a[i][2],a[i][3]);
		}
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
		{
			who[2].emplace_back(i);
			cha[i]=a[i][2]-max(a[i][1],a[i][3]);
		}
		else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2])
		{
			who[3].emplace_back(i);
			cha[i]=a[i][3]-max(a[i][1],a[i][2]);
		}
	}
	if(who[1].size()>(n>>1))
	{
		sort(who[1].begin(),who[1].end(),cmp);
		for(long long i=0;i<who[1].size()-(n>>1);i++)
		{
			ans-=cha[who[1][i]];
		}
	}
	else if(who[2].size()>(n>>1))
	{
		sort(who[2].begin(),who[2].end(),cmp);
		for(long long i=0;i<who[2].size()-(n>>1);i++)
		{
			ans-=cha[who[2][i]];
		}
	}
	else if(who[3].size()>(n>>1))
	{
		sort(who[3].begin(),who[3].end(),cmp);
		for(long long i=0;i<who[3].size()-(n>>1);i++)
		{
			ans-=cha[who[3][i]];
		}
	}
	printf("%lld\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	scanf("%lld",&t);
	while(t--)
	{
		solve();
	}
} 
