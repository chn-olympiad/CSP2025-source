#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,c[505],ans,st,kl;
long long dp[22][530005];
string s;
int cmp(long long A,long long B) {
	return A>B;
}
int main() {
	//3 2 101 1 1 2
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1; i<=n; i++) {
		scanf("%lld",&c[i]);
	}
	sort(c+1,c+n+1,cmp);
	st=(1ll<<n)-1;
	dp[0][0]=1;
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=st; j++) {
			kl=0;//面试过的人
			for(int op=0; op<=n-1; op++) {
				if((j&(1<<op))!=0) {
					kl++;
				}
			}
			if(kl>=i) {
				for(int op=0; op<=n-1; op++) {
					if((j&(1<<op))==0) {
						if(s[kl]=='1'&&c[op+1]>kl-i) {
							dp[i+1][j+(1<<op)]+=dp[i][j];
							dp[i+1][j+(1<<op)]%=mod;
						} else {
							dp[i][j+(1<<op)]+=dp[i][j];
							dp[i][j+(1<<op)]%=mod;
						}
					}
				}
			}
		}
	}
	for(int i=m; i<=n; i++) {
		ans=(ans+dp[i][st])%mod;
	}
	cout<<ans;
	return 0;
}