#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3;
int n,a[N],dp[N+5],t,a2,ans,mod=998244353;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	dp[0]=1;
	a2=1;
	for(int i=1;i<=n;i++)
	{
		t=0;
		for(int j=0;j<=a[i];j++)
			t=(t+dp[j])%mod;
		t=(a2-t+mod)%mod;
		ans=(ans+t)%mod;
		for(int j=N-a[i];j>=0;j--)
			dp[j+a[i]]=(dp[j+a[i]]+dp[j])%mod;
		a2=(a2*2)%mod;
	}
	cout<<ans<<"\n";
	return 0;
}
