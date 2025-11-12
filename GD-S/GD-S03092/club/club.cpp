#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,maxn;
int a[200006][4],a2[200006];
bool tag = 0;
void dfs(int pos,int ans,int cnt1,int cnt2,int cnt3)
{
	if(pos == n+1)
	{
		maxn = max(ans,maxn);
		return ;
	}
	if(cnt1 < n/2) dfs(pos+1,ans+a[pos][1],cnt1+1,cnt2,cnt3);
	if(cnt2 < n/2) dfs(pos+1,ans+a[pos][2],cnt1,cnt2+1,cnt3);
	if(cnt3 < n/2) dfs(pos+1,ans+a[pos][3],cnt1,cnt2,cnt3+1);
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		maxn = 0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++) 
		{
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][2] != 0 || a[i][3] != 0) tag = 1;
		}
		if(!tag)
		{
			for(int i=1;i<=n;i++) a2[i] = a[i][1];
			sort(a2+1,a2+1+n);
			for(int i=n/2+1;i<=n;i++) maxn += a2[i];
			printf("%lld\n",maxn);
			return 0;
		}
		dfs(0,0,0,0,0);
		printf("%lld\n",maxn);
	}
	return 0;
}
