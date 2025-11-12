#include<bits/stdc++.h>
#define int  long long
using namespace std;
const int mod=998244353;
int n,m;
string s;
int c[100005];
int dp[1000000][20];
int calc(int x){
	int res=0;
	while(x){
		res+=(x%2);
		x/=2;
	}
	return res;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++)cin>>c[i];
	dp[0][0]=1;
	for(int msk=0;msk<(1<<n);msk++){
		int tot=calc(msk);
		for(int i=1;i<=n;i++){
			if(msk&(1<<(i-1)))continue;
			int nxt=msk|(1<<(i-1));
			for(int j=0;j<=n;j++){
				if(s[tot+1]=='0'){
					dp[nxt][j+1]=(dp[msk][j]+dp[nxt][j+1])%mod;
				}else{
					if(j<c[i])dp[nxt][j]=(dp[msk][j]+dp[nxt][j])%mod;
					else dp[nxt][j+1]=(dp[msk][j]+dp[nxt][j+1])%mod;
				}
			}
		}
	}
	int sum=0;
	for(int i=0;i<=n-m;i++){
		sum+=dp[(1<<n)-1][i];
		sum%=mod;
	}
	cout<<sum<<endl;
	return 0;
}

