#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int a[5005],ans;
int dp[5005];
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return ans;
}
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n);
	dp[0]=1;
	ans=qpow(2,n)-1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=a[i];j++)
		ans=(ans-dp[j]+mod)%mod;
		for(int j=5000-a[i];j>=0;j--)
		dp[j+a[i]]=(dp[j+a[i]]+dp[j])%mod;
	}
	cout<<ans;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(),cout.tie();
	int t=1;
//	cin>>t;
	while(t--)solve();
	return 0;
}

// Chtholly Nota
