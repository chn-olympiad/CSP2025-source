#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=20,S=(1<<18),mod=998244353;
int n,m,c[N],cnt[S];
string s;
ll ans,dp[S][N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=0;i<(1<<n);i++) for(int j=0;j<n;j++) cnt[i]+=(i>>j&1);
	dp[0][0]=1;
	for(int i=0;i<(1<<n);i++){
		for(int k=0;k<=cnt[i];k++){
			for(int j=0;j<n;j++){
				if(i>>j&1) continue;
				if(s[cnt[i]]=='0'||k>=c[j+1]) dp[i+(1<<j)][k+1]+=dp[i][k],dp[i+(1<<j)][k+1]%=mod;
				else dp[i+(1<<j)][k]+=dp[i][k],dp[i+(1<<j)][k]%=mod;
			}
		}
	}
	for(int i=0;i<=n-m;i++) ans+=dp[(1<<n)-1][i],ans%=mod;
	cout<<ans;
	return 0;
}
