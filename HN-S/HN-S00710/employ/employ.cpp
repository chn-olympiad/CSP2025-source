#include<bits/stdc++.h>
#define lint long long
using namespace std;
const int kN=1e5+10,kM=1e5+10,kMod=998244353;

int popcount(int);

int flag[kN],val[kN],dp[19][19][1<<18];

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,vis=1;cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char x;cin>>x;
		flag[i]=x-'0';
	}
	for(int i=1;i<=n;i++)cin>>val[i];
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<i;j++)
			for(int k=0;k<(1<<n);k++)
				if(popcount(k)==i)	
					for(int p=1;p<=n;p++)
						if(k&(1<<p-1))
							if((val[p]<=j||flag[i]==0))(dp[i][j+1][k]+=dp[i-1][j][k^(1<<p-1)])%=kMod;
							else (dp[i][j][k]+=dp[i-1][j][k^(1<<p-1)])%=kMod;
	int ans=0;
	for(int i=0;i<=n-m;i++)(ans+=dp[n][i][(1<<n)-1])%=kMod;
	cout<<ans<<endl;
}

int popcount(int k)
{
	int res=0;
	while(k)res+=k%2,k/=2;
	return res;
}