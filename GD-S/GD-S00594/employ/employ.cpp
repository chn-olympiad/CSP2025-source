#include <bits/stdc++.h>
#define MAXN 505
using namespace std;
using ll = long long;
const int mod = 998244353;
int n,m;
string s;
int c[MAXN];
ll dp[1<<19][22];
int main(){
#ifndef SVK
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++)cin>>c[i];
	dp[0][0]=1;
	for(int S=0;S<(1<<n);S++){
		int d = __builtin_popcount(S);
		for(int i=0;i<=n;i++){
			for(int j=0;j<n;j++){
				if((S>>j)&1)continue;
				int T = S | (1<<j);
				if(s[d]=='0' || d-i>=c[j])(dp[T][i]+=dp[S][i])%=mod;
				else (dp[T][i+1]+=dp[S][i])%=mod;
			}
		}
	}
	ll ans = 0;
	for(int i=m;i<=n;i++)(ans+=dp[(1<<n)-1][i])%=mod;
	cout<<ans<<"\n";
	return 0;
}

