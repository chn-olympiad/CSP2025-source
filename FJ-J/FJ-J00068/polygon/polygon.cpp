#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define mpi make_pair
#define fi first
#define se second
#define lb(x) (x&-x)
using namespace std;
const int maxn=5e3+10;
const int maxm=1e6+10;
const int mod=998244353;
int n,a[maxn],dp[maxn],ans;
inline int qpow(int k,int b)
{
	int res=1;
	while (b)
	{
		if (b&1) res=res*k%mod;
		k=k*k%mod;
		b>>=1;
	}
	return res;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	ans=(qpow(2,n)-1-n-n*(n-1)%mod*qpow(2,mod-2)%mod+mod)%mod;
	dp[0]=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=a[i];j++) ans=(ans-dp[j]+mod)%mod;
		ans=(ans+i)%mod;
		for (int j=5000;j>=a[i];j--) dp[j]=(dp[j]+dp[j-a[i]])%mod;
	}
	cout << ans;
	return 0;
}
