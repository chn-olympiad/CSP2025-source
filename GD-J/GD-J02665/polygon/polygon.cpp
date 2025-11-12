#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,M=1e5+5,mod=998244353;
int n;
int a[N];
int dp[M];
int ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int V=0;
	for(int i=1;i<=n;i++)
		cin>>a[i],V+=a[i];
	V=min(V,10001);
	sort(a+1,a+n+1);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=a[i]+1;j<=V;j++)
			ans=(ans+dp[j])%mod;
		for(int j=V;j>=0;j--)
			dp[min(j+a[i],10001)]=(dp[min(j+a[i],10001)]+dp[j])%mod;
	}
	cout<<ans;
	return 0;
}
/*
按边排序
DP[i][j]表示前i个，和为j的方案数
DP[I][10001]表示前i个 大于等于10001的方案数 
*/
