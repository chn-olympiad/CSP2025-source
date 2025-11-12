#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=6005;
const int mod=998244353;
int n,a[MAXN],ans;
int dp[MAXN][MAXN];
void dfs(int k,int sum,int maxx,int cnt){
	if(k>n){
		if(cnt>=3&&sum>2*maxx){
			ans++;
			ans%=mod;
		}
		return;
	}
	dfs(k+1,sum,maxx,cnt);
	dfs(k+1,sum+a[k],max(maxx,a[k]),cnt+1);
}
int quickpow(int x,int y){
	int num=x,ansn=1;
	while(y!=0){
		if(y&1) ansn=(ansn*num+mod)%mod;
		num=(num*num+mod)%mod;
		y/=2;
	}
	return ansn;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(n<=20){
		dfs(1,0,0,0);
		cout<<ans%mod<<endl;
		return 0;	
	}
	sort(a+1,a+1+n);
	for(int i=0;i<=n;i++) dp[i][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[n];j++){
			dp[i][j]=dp[i-1][j];
			if(j>=a[i]) dp[i][j]+=dp[i-1][j-a[i]];
			dp[i][j]=(dp[i][j]+mod)%mod;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[n];j++){
			dp[i][j]+=dp[i][j-1];
			dp[i][j]=(dp[i][j]+mod)%mod;
		}
	}
	for(int i=3;i<=n;i++){
		ans+=(quickpow(2,i-1)-dp[i-1][a[i]]+mod)%mod;
		ans=(ans+mod)%mod;
	}
	cout<<ans%mod<<endl;
	return 0;
}
