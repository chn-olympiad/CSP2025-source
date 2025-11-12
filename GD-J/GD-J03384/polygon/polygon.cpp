#include<bits/stdc++.h>
using namespace std;
const int N=5010,mod=998244353;
int n,a[N],dp[N][N],g[N],pw[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;pw[0]=1;
	for(int i=1;i<=n;i++)cin>>a[i],pw[i]=pw[i-1]*2%mod;
	sort(a+1,a+1+n);
	dp[0][0]=1;g[0]=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<=a[n];j++){
			dp[i][j]=dp[i-1][j];
			if(j>=a[i])(dp[i][j]+=dp[i-1][j-a[i]])%=mod;
			if(j<=a[i+1])(g[i]+=dp[i][j])%=mod;
		}
	}
	int res=0;
	for(int i=1;i<=n;i++){
		int k=(pw[i-1]-g[i-1]+mod)%mod;
		(res+=k)%=mod;
	}cout<<res;
	return 0;
} 
