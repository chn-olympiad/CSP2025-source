#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=9982443553;
int n,c[505],m,dp[20][20][500005];
string s;
int ct(int x){
	int r=0;
	while (x){
		r+=(x&1);
		x>>=1;
	}
	return r;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	s=" "+s;
	for (int i=1;i<=n;i++){
		cin>>c[i];
	}
	if (n<=18){
		dp[1][0][0]=1;
		for (int i=1;i<=n;i++){
			for (int j=0;j<i;j++){
				for (int k=0;k<(1<<n);k++){
					if (ct(k)!=i-1){
						continue;
					}
					for (int l=0;l<n;l++){
						if (k & (1<<l)){
							continue;
						}
						int fl=((s[i]-'0')==1 && j<c[l+1]);
						if (fl){
							dp[i+1][j][k+(1<<l)]=(dp[i+1][j][k+(1<<l)]+dp[i][j][k])%mod;
						}else{
							dp[i+1][j+1][k+(1<<l)]=(dp[i+1][j+1][k+(1<<l)]+dp[i][j][k])%mod;
						}
//						cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
					}
				}
			}
		}
		int ans=0;
		for (int i=0;i+m<=n;i++){
			ans=(ans+dp[n+1][i][(1<<n)-1])%mod;
		}
		cout<<ans;
	}else if (m==n){
		int fl=1;
		for (int i=1;i<=n;i++){
			if (s[i]=='0' || c[i]==0){
				fl=0;
			}
			fl=fl*i%mod;
		}
		cout<<fl;
	}else{
		cout<<0;
	}
}
/*
orz wj NOI2025 Au
orz lxz NOI2026 Au
orz wsy NOI2028 Au && AT *2800
orz cyq CF*4091 && have 10^1000 dollars
orz xza high test 799pts
*/
