#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll n,m,s[505],c[505],p[505],ans,dp[(1<<18)+5][20],s2[505],cnt2;
ll sum2[505];
bool flag[505];
void dfs(ll dep){
	if(dep==n+1){
		ll cnt=0,sum=0;
		for(int i=1;i<=n;i++){
			if(s[i]==0){
				++cnt;
				continue;
			}
			if(cnt>=c[p[i]])++cnt;
			else ++sum; 
		}
		if(sum>=m)ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(flag[i])continue;
		flag[i]=1;
		p[dep]=i;
		dfs(dep+1);
		flag[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++){
		char x;
		cin >>x;
		s[i]=x-'0';
		if(!s[i])f=0;
	}
	for(int i=1;i<=n;i++)cin >>c[i];
	for(int i=1;i<=n;i++){
		if(s[i])s2[++cnt2]=i;
		sum2[i]=sum2[i-1]+(!s[i]);
	}
	if(n<=18){
//		sort(c+1,c+1+n);
//		reverse(c+1,c+1+n);
		dp[0][0]=1;
		for(int i=0;i<(1<<n)-1;i++){
			ll x=__builtin_popcount(i);
//			cout <<i<<" "<<x<<"\n";
			for(int j=0;j<=x;j++){
				for(int k=1;k<=n;k++){
					if(!((i>>(k-1))&1)){
//						cout <<i<<" "<<k<<"\n";
						if(!s[x+1]||j>=c[k]){
							dp[i|(1<<(k-1))][j+1]=(dp[i|(1<<(k-1))][j+1]+dp[i][j])%mod;
						}else{
							dp[i|(1<<(k-1))][j]=(dp[i|(1<<(k-1))][j]+dp[i][j])%mod; 
						}
					}
				}
			}
		}
		for(int i=0;i<=n;i++){
			if(n-i>=m){
//				cout <<i<<" "<<dp[(1<<n)-1][i]<<"\n";
				ans=(ans+dp[(1<<n)-1][i])%mod;
			}
		}
		cout <<ans;
		return 0;
	}
	dfs(1);
	cout <<ans;
}
