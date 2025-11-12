#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,dp[505][205][505],a[5005],mx,cnt,ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(a[i],mx);
		cnt+=a[i];
	}
	if(mx<=1){
		int res=0;
		for(int i=1;i<=n;i++){
			res=0; 
			for(int j=i;j<=n;j++){
				res+=a[i];
				if(res>=3) ans++;
			} 
		}
		cout<<ans<<endl;
	}else{
		dp[0][0][0]=1;
		cnt=min(cnt,500*1ll);
		cout<<cnt<<endl;
		for(int i=1;i<=n;i++){
			cout<<i<<endl;
			for(int j=0;j<=mx;j++){
				for(int k=0;k<=cnt;k++){
					dp[i][max(j,a[i])][min(k+a[i],500*1ll)]=(dp[i-1][j][k]+dp[i][max(j,a[i])][min(k+a[i],500*1ll)])%mod;
					dp[i][j][k]=(dp[i][j][k]+dp[i-1][j][k])%mod;
				}
			}
		}
		for(int j=0;j<=mx;j++){
			for(int k=0;k<=cnt;k++){
				if(j*2<k){
					ans=(ans+dp[n][j][k])%mod;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
