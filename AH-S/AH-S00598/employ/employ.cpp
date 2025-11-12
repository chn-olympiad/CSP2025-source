#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5,MOD=998244353;
long long i,n,m,li[N],sum1,sum2,dp[N],ans=1;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	for(i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if(x==0)sum1++;
	}
	for(i=1;i<=n-sum1;i++)ans*=i,ans%=MOD;
	cout<<ans;
	return 0;
}
