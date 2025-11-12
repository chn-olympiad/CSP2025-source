#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,c[N],ans,dp[1<<19][30];
string s;
int C(int S)
{
	int res=0;
	for(int i=0;i<n;i++)
		if(S&(1<<i))res++;
	return res;
}
signed main()
{
//	cin.tie(0)->sync_with_stdio(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++)cin>>c[i];
	if(n<=18){
		dp[0][0]=1;
		for(int S=0;S<(1<<n);S++)
		for(int j=0;j<=m;j++)
		{
			int cnt=C(S);
			if(cnt<j)continue;
			for(int i=0;i<n;i++)
			{
				if(S&(1<<i))continue;
				if(s[cnt]=='0')dp[S|(1<<i)][j]+=dp[S][j];
				else{
					if(cnt-j>=c[i])
					dp[S|(1<<i)][j]+=dp[S][j];
					else 
					dp[S|(1<<i)][j+1]+=dp[S][j];
				}
				dp[S|(1<<i)][j]%=mod;
				dp[S|(1<<i)][j+1]%=mod;
			}
		}
		int kkk=(1<<n)-1;
		for(int i=m;i<=n;i++)
			ans+=dp[kkk][i],ans%=mod;
		cout<<ans<<endl;
	}
	else cout<<0<<endl;
	return 0;
}
/*

3 2
101
1 1 2
*/
