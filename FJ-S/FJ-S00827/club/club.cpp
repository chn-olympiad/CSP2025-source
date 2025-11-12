#include<bits/stdc++.h>
using namespace std;
using lld = long long;
const lld siz = 2e2+5;
const lld mod = 1e9+7;
using pll = pair<lld,lld>;

lld t,n,ans;
lld a[(lld)1e5+5][3];
lld dp[siz][siz][siz];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		ans = 0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
			for(int j=0;j<3;j++)
				scanf("%lld",&a[i][j]);
		if(n<205)
		{
			memset(dp,-0x3f,sizeof dp);
			dp[0][0][0] = 0;
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<=min(i*1ll,n/2);j++)
				{
					for(int k=0;k<=min((i-j)*1ll,n/2);k++)
					{
						if(i-j-k>n/2) continue;
						lld x = dp[i-1][j][k]+a[i][2],y = 0,z = 0;
						if(k>0) y = dp[i-1][j][k-1]+a[i][1];
						if(j>0) z = dp[i-1][j-1][k]+a[i][0];
						dp[i][j][k] = max(x,max(y,z));
						if(i == n) ans = max(ans,dp[i][j][k]);
					}
				}
			}
			printf("%lld\n",ans);
		}
		else
		{
			vector<lld> vec;
			ans = 0;
			for(int i=1;i<=n;i++)
			{
				ans+=a[i][0];
				vec.push_back(a[i][1]-a[i][0]);
			}
			sort(vec.begin(),vec.end(),greater<lld>());
			for(int i=0;i<n/2;i++)
				ans+=vec[i];
			printf("%lld\n",ans);
		}
	}
	return 0;
}
