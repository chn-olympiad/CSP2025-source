#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lll __int128
#define md 998244353
const int mxn=201;
int n;
#define upd(x,y) x=max(x,y)
namespace subtask1
{
	int dp[201][201][201];
	void main()
	{
		memset(dp,-0x3f,sizeof(dp));
		for (int i=0;i<=n;i++)
		{
			dp[i][0][0]=0;
		}
		for (int i=1;i<=n;i++)
		{
			int a,b,c; cin>>a>>b>>c;
			for (int j=0;j<=i&&j<=n/2;j++)
			{
				for (int k=0;k<=i-j&&k<=n/2;k++)
				{
					int f=i-j-k;
					if (f>n/2) continue;
					dp[i][j][k]=dp[i-1][j][k];
					if (j>0) upd(dp[i][j][k],dp[i-1][j-1][k]+a);
					if (k>0) upd(dp[i][j][k],dp[i-1][j][k-1]+b);
					if (f>0) upd(dp[i][j][k],dp[i-1][j][k]+c);
				}
			}
		}
		int ans=0;
		for (int i=0;i<=n;i++)
		{
			for (int j=0;j<=n;j++) ans=max(ans,dp[n][i][j]);
		}
		cout<<ans<<'\n';
	}
}
namespace subtask2
{
	int a[1000050][3],b[100050];
	inline void solve2()
	{
		int ans=0;
		for (int i=1;i<=n;i++) b[i]=max(a[i][0],max(a[i][1],a[i][2]));
		sort(b+1,b+1+n,greater<int>());
		for (int i=1;i<=n;i++) ans+=b[i];
		cout<<ans<<'\n';
		return void();
	}
	void main()
	{
		for (int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
		for (int i=1;i<=n;i++)
		{
			if (a[i][1]||a[i][2]) return solve2(),void();
			b[i]=a[i][0];
		}
		int ans=0;
		sort(b+1,b+1+n,greater<int>());
		for (int i=1;i<=n/2;i++) ans+=b[i];
		cout<<ans<<'\n';
	}
}
signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while (T--)
	{
		cin>>n;
		if (n<=200) subtask1::main();
		else subtask2::main();
	}
	return 0;
}
/*
正在比较文件 club1.out 和 CLUB1.ANS
FC: 找不到差异
正在比较文件 club2.out 和 CLUB2.ANS
FC: 找不到差异
正在比较文件 club3.out 和 CLUB3.ANS
FC: 找不到差异
正在比较文件 club4.out 和 CLUB4.ANS
FC: 找不到差异
正在比较文件 club5.out 和 CLUB5.ANS
FC: 找不到差异
签到不成功，喜提70pts，不嬉戏 
*/