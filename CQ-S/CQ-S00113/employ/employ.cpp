#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,a[510],dp[(1<<18)+10][20],b[510],cnt,dp1[510][510],fac[510],sum[510];
string s;
inline int popcount(int x){
	int res=0;
	for(int i=0;i<n;i++)
		if(x&(1<<i)) res++;
	return res;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dp[0][0]=1;
	for(int i=1;i<(1<<n);i++){
		int pc=popcount(i);
		for(int j=0;j<n;j++)
			if(i&(1<<j))
				for(int k=0;k<=n;k++){
					int cg=0;
					if(k>=a[j+1]||s[pc]=='0') cg=1;
					(dp[i][k+cg]+=dp[i-(1<<j)][k])%=mod;
				}
	}
	int ans=0;
	for(int i=0;i<=n-m;i++)
		(ans+=dp[(1<<n)-1][i])%=mod;
	cout<<ans;
	return 0;
}
