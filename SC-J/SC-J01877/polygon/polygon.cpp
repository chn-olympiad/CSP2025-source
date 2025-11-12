#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,s[5005],dp[5005][10005],ans,sum,mod=998244353;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;for(int i=1;i<=n;i++)cin>>s[i];
	sort(s+1,s+1+n);dp[2][0]=1;sum=s[1]+s[2];for(int i=0;i<=sum;i++)dp[2][i]+=1;
	for(int i=0;i<=s[1];i++)dp[2][i]+=1;
	for(int i=0;i<=s[2];i++)dp[2][i]+=1;
	for(int i=3;i<=n;i++){
		ans=(ans+dp[i-1][s[i]+1])%mod;sum+=s[i];
		for(int j=min((int)10002,sum);j>-1;j--){
			dp[i][j]=(dp[i-1][j]+dp[i-1][max((int)0,j-s[i])])%mod;
		}
	}
	cout<<ans;
	return 0;
}