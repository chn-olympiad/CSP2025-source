#include<bits/stdc++.h>
using namespace std;
const int N=505,M=998244353;
int n,m,c[N];
string s;
int dp[1<<18][20];
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;s=" "+s;
	for(int i=0;i<n;i++)cin>>c[i];
	int cnt=0;
	for(int i=1;i<=n;i++)cnt+=s[i]-'0';
	if(cnt<m){
		cout<<0;
		return 0;
	}
	dp[0][0]=1;
	for(int i=1;i<(1<<n);i++){
		int d=__builtin_popcount(i);
		for(int j=0;j<n;j++){
			if(!((i>>j)&1))continue;
			for(int r=0;r<=d;r++)dp[i][r+(c[j]<=r||s[d]=='0')]=(dp[i][r+(c[j]<=r||s[d]=='0')]+dp[i^(1<<j)][r])%M;
		}
	}
	int ans=0;
	for(int i=0;i<=n-m;i++)ans=(ans+dp[(1<<n)-1][i])%M;
	cout<<ans;
	return 0;
}

