#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n;
int s[5005];
int k[5005];
int dp[25000005];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	int mx=0;
	int qm=-1;
	dp[0]=1;
	for(int i=1;i<=n;i++)cin>>s[i],mx+=s[i],qm=max(qm,s[i]);
	if(qm==1){
		cout<<n-2;
		return 0;
	}
	sort(s+1,s+1+n);
	int ans=0;
	for(int i=1;i<=n;i++){
		k[i]=k[i-1]+s[i];
		for(int j=mx;j>=s[i];j--){
			dp[j]+=dp[j-s[i]];
			dp[j]%=mod;
		}
		
		for(int j=2*s[i]+1;j<=k[i];j++)ans+=dp[j],ans%=mod;
	}
	cout<<ans;
	return 0;
}