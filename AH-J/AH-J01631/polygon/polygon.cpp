#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,a[5005],dp[5005],b[5005],s[5005],dp1[5005],ans;
void work(int w){
	for(int i=0;i<=m+1;i++)dp1[i]=dp[i];
	for(int i=0;i<=m+1;i++){
		int j=min(i+w,m+1);
		dp[j]=(dp[j]+dp1[i])%mod;
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m=max(m,a[i]);
	}dp[0]=1;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=m+1;j>a[i];j--)s[j]=(s[j+1]+dp[j])%mod;
		ans=(ans+(s[a[i]+1]))%mod;
		work(a[i]);
	}
	cout<<ans<<"\n";
	return 0;
}
