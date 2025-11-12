#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lll __int128
#define md 998244353
#define nw (i&1)
#define lst ((i&1)^1)
#define upd(x,y) x=(x+y)%md
const int mxn=18;
int n,m,dp[2][(1<<mxn)+1][mxn+1],c[mxn+1],ans;
string s;
signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s; s=" "+s;
	for (int i=1;i<=n;i++) cin>>c[i];
	dp[0][0][0]=1;
	for (int i=1;i<=n;i++)//第i天
	{
		memset(dp[nw],0,sizeof(dp[nw]));
		for (int j=0;j<(1<<n);j++)//上一个局面为j
		{
			if (__builtin_popcount(j)!=i-1) continue;//上一个局面有 (i-1) 人
			for (int k=1;k<=n;k++)//这一天第k人面试
			{
				if ((j>>(k-1))&1) continue;//已经面试过了
				for (int f=0;f<i;f++)//上一局面有f人通过
				{
					if (c[k]<=(i-f-1)||s[i]=='0') upd(dp[nw][j|(1<<(k-1))][f],dp[lst][j][f]);//懒得面试或不让你过，就不让你过
					else upd(dp[nw][j|(1<<(k-1))][f+1],dp[lst][j][f]);//录取你
				}
			}
		}
	}
	ans=0;
	for (int i=m;i<=n;i++) upd(ans,dp[n&1][(1<<n)-1][i]);
	cout<<ans<<'\n';
	return 0;
}
//dp[i][j][k] 表示第i天，当前局面为j其中k人通过面试的方案数
//init: dp[0][0]=1;
//从dp[i-1][S \in j ]- > dp[i][j];
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/