#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,dp[1<<18][20],c[200005];
const int mod=998244353;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	string s;cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	dp[0][0]=1;
	for(int i=0;i<(1<<n);i++){
		int sum=0;for(int j=0;j<n;j++){if((i&(1<<j))) sum++;}
		for(int k=0;k<n;k++){
			if((i&(1<<k))) continue;
			if(s[sum]=='1')
			for(int j=0;j<=sum;j++){
				if(c[k+1]<=j){
					dp[(i|(1<<k))][j+1]=(dp[(i|(1<<k))][j+1]+dp[i][j])%mod;
				}
				else{
					dp[(i|(1<<k))][j]=(dp[(i|(1<<k))][j]+dp[i][j])%mod;	
				}
			}
			else{
				for(int j=0;j<=sum;j++){
					dp[(i|(1<<k))][j+1]=(dp[(i|(1<<k))][j+1]+dp[i][j])%mod;	
				}	
			}
		}
	}
	int ans=0,num=(1<<n)-1;
	for(int i=0;i<=n-m;i++){
		ans+=dp[num][i];ans%=mod;
	}
	cout<<ans;
	return 0;
}
/*
先开暴力分，把总分冲上200再说 
*/
