#include<bits/stdc++.h>
using namespace std;
#define LL long long
const LL N=5010,P=998244353;
int a[N];LL dp[N][N];
LL count(int x,int y)
{
	LL ans=0;
	for(int i=y+1;i<=5001;i++)ans=(dp[x][i]+ans)%P;
	return ans;
}
void mod(LL &x){x=(x%P+P)%P;}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//	freopen("hack1.in","r",stdin);
	memset(dp,0,sizeof(dp));
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	dp[0][0]=1;
	LL ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=count(i-1,a[i]),mod(ans);
		for(int j=0;j<=5001;j++)
		{
			int sum=min(j+a[i],5001);
			dp[i][sum]+=dp[i-1][j];mod(dp[i][sum]);
			dp[i][j]+=dp[i-1][j];mod(dp[i][j]);
		}
	}
	cout<<ans;
	return 0;
}

