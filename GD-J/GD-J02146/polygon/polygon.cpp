#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5005;
const int mod=998244353;
int n,a[maxn],dp[maxn<<1],ans;
inline int cal(int maxx,int s){
	int sum=0;
	for(int i=maxx;i>=s;i--){
		dp[i]=(dp[i]+dp[i-s])%mod;
		if(i<=2*s)sum=(sum+dp[i-s])%mod;
	}
	return sum;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	ans=1;
	for(int i=1;i<=n;i++) ans=(ans*2)%mod;
	sort(a+1,a+1+n);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		int qwq=cal(a[n]*2,a[i]);
		ans=(ans-qwq+mod)%mod;
	}
	cout<<(ans+mod-1)%mod;
	return 0;
}
