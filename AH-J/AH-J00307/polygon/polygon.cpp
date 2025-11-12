#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define ll long long  
ll mod=998244353;
ll dp[5005][5005]; 
ll a[5005] ;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout); 
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<5000;j++){
		    dp[i][j]=dp[i-1][j];
		}
	    for(int j=a[i]+1;j<=5000;j++){
		    dp[i][j+a[i]]=max(dp[i][j],dp[i][j+a[i]]+dp[i-1][j])%mod;
		}
	}
	cout<<dp[n][n];
    return 0;
}
