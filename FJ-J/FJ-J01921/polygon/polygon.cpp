#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5010,M=10010,mod=998244353;
int n,m,a[N];
int now;ll dp[2][M],ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n),m=a[n]*2+1;
	dp[now=0][0]=1;
	for(int i=1;i<=n;i++)
	{
		int noww=now^1;
		memset(dp[noww],0,sizeof(dp[noww]));
		for(int j=0;j<=m;j++)
		  dp[noww][j]=(dp[now][j]+dp[now][max(0,j-a[i])])%mod;
		ans+=dp[now][a[i]+1],ans%=mod;
		now=noww;
	}
	cout<<ans;
	return 0;
}
