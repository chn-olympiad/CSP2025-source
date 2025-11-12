#include<bits/stdc++.h>
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define _antirep(i,a,b) for(int i=(a);i>=(b);--i)
#define int LL
using namespace std;
typedef long long LL;
const int N=5e3+5,mod=998244353;

int n,ans;
int a[N];
int dp[N*N];

signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n;
	int sum=0;
	_rep(i,1,n) cin>>a[i],sum+=a[i];
	
	sort(a+1,a+n+1);
	
	dp[0]=1;
	_rep(i,1,n)
	{ 
		_rep(j,a[i]+1,sum) 
			ans=(ans+dp[j])%mod;  
		_antirep(j,sum,a[i])
			dp[j]=(dp[j]+dp[j-a[i]])%mod;
	}
	 
	cout<<ans<<"\n"; 
	return 0;
} 

