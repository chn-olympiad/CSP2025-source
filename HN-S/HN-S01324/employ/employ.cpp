#include<bits/stdc++.h>
using namespace std;
#define int long long 

const int N=25,mod=998244353;
int n,m,dp[1ll<<19][N],a[N];
string s;

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	if(n==m)
	{
		for(int i=1;i<=n;i++)
		{
			char ch;
			cin>>ch;
			if(ch=='0')
			{
				cout<<"0\n";
				return 0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			if(x==0)
			{
				cout<<"0\n";
				return 0;
			}
		}
		int ans=1;
		for(int i=1;i<=n;i++)
			ans=(ans*i)%mod;
		cout<<ans<<"\n";
		return 0;
	}
	cin>>s;
	for(int i=0;i<n;i++)
		cin>>a[i];
	dp[0][0]=1;
	for(int i=1;i<(1ll<<n);i++)
	{
		int tmp=__builtin_popcountll(i);
		for(int j=0;j<=tmp;j++)
			for(int k=0;k<n;k++)
				if((i>>k)&1)
				{
					if(tmp-j>=a[k]||s[tmp-1]=='0')
						dp[i][j]=(dp[i][j]+dp[i^(1ll<<k)][j])%mod;
					else if(j>0)
						dp[i][j]=(dp[i][j]+dp[i^(1ll<<k)][j-1])%mod;
				}
//		cerr<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<" "<<dp[i][3]<<" "<<dp[i][4]<<" "<<dp[i][5]<<" "<<dp[i][6]<<" "<<dp[i][7]<<" "<<dp[i][8]<<" "<<dp[i][9]<<" "<<dp[i][10]<<"\n";
	}
	int ans=0;
	for(int j=m;j<=n;j++)
		ans=(ans+dp[(1ll<<n)-1][j])%mod;
	cout<<ans<<"\n";
	return 0;
}
