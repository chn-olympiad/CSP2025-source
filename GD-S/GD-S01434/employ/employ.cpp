#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
int n,m,a[505],b[505];
char in[505];
ll dp[20][20][1<<18],ans,cnt;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>in;
	for(int i=0;i<n;++i)cin>>a[i],++b[a[i]];
	dp[0][0][0]=1;
	for(int i=0;i<n;++i)
	for(int j=0;j<=i;++j)
	for(int k=0;k<(1<<n);++k)
	if(__builtin_popcount(k)==i){
		for(int x=0;x<n;++x)
		if(!(k&(1<<x))){
			if(a[x]<=i-j||in[i]=='0')dp[i+1][j][k^(1<<x)]=(dp[i+1][j][k^(1<<x)]+dp[i][j][k])%mod;
			else dp[i+1][j+1][k^(1<<x)]=(dp[i+1][j+1][k^(1<<x)]+dp[i][j][k])%mod;
		}
	} 
	for(int j=m;j<=n;++j)ans=(ans+dp[n][j][(1<<n)-1])%mod;
	cout<<ans;
	return 0;
}/*
前面失败了(i-1-j)个
*/
