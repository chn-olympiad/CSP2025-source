#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
long long dp[5010][10005];
long long ans,f[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=5001;j++){
			dp[i-1][j]%=998244353ll;
			dp[i][j]+=dp[i-1][j];
			dp[i][min(5001,j+a[i])]+=dp[i-1][j];
		}
	}
	for(int i=1;i<=n;i++){ 
		f[a[i]]=-1;
		for(int j=5001;j>a[i+1];j--){
			dp[i][j]+=dp[i][j+1]+f[j];
			dp[i][j]%=998244353ll;
		}
	}
	for(int i=2;i<=n;i++){
		ans+=dp[i-1][a[i]+1];
		ans%=998244353ll;
	}
	cout<<ans;
	return 0;
}