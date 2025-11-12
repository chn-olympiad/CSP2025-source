#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)
#define sf scanf
#define pf printf
const ll mod=998244353;
ll n,a[5005],dp[10005][4],ans; 
int main(){
	fin("polygon.in");
	fout("polygon.out");
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=10001;j>=10001-a[i];j--){
			dp[10001][3]=((dp[10001][3]+dp[j][2])%mod+dp[j][3])%mod;
		}
		for(int j=10000;j>a[i]*2;j--){
			dp[j][3]=((dp[j-a[i]][3]+dp[j-a[i]][2])%mod+dp[j][3])%mod;
		}
		for(int j=a[i]*2;j>a[i];j--){
			dp[j][2]=((dp[j-a[i]][1]+dp[j-a[i]][2])%mod+(dp[j-a[i]][3]+dp[j][2])%mod)%mod;
		}
		dp[a[i]][1]++;
		dp[a[i]][1]%=mod;
	}
	for(int i=3;i<=10001;i++){
		ans=(ans+dp[i][3])%mod;
	}
	cout<<ans;
	return 0;
}
