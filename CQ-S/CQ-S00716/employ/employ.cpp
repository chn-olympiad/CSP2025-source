#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[20],s[20],num;
int dp[20][(1<<18)][20];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	string ss;cin>>ss;
	for(int i=0;i<n;i++){
		s[i+1]=ss[i]-'0';
		num+=s[i+1];
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	if(num<m){
		cout<<0;
		return 0;
	}else if(n<18){
		dp[0][0][0]=1;
		for(int i=0;i<n;i++){
			for(int j=0;j<(1<<n);j++){
				bitset<20>bt=j;
				if((int)bt.count()!=i)continue;
				for(int k=0;k<=i;k++){
					if(dp[i][j][k]==0)continue;
					for(int x=1;x<=n;x++){
						if(bt[x-1])continue;
						if(c[x]<=i-k||s[i+1]==0)
							dp[i+1][j|(1<<(x-1))][k]=(dp[i+1][j|(1<<(x-1))][k]+dp[i][j][k])%mod;
						else
							dp[i+1][j|(1<<(x-1))][k+1]=(dp[i+1][j|(1<<(x-1))][k+1]+dp[i][j][k])%mod;
					}
				}
			}
		}
		int ans=0;
		for(int i=m;i<=n;i++){
			ans=(ans+dp[n][(1<<n)-1][i])%mod;
		}cout<<ans;
	}
	return 0;
}

