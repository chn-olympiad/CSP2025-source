#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define int long long
const int mod = 998244353;
int n;
int a[5010];
int dp[25000010];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int sum = 0;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dp[0] = 1;
	int ans = 0;
	for(int i = 1;i<=n;i++){
		sum+=a[i];
		for(int j = sum;j>a[i];j--)ans = (ans+dp[j])%mod;
		for(int j = sum;j>=a[i];j--){
			dp[j] = (dp[j]+dp[j-a[i]])%mod;
		}
	}
	cout<<ans;
}
