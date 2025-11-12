#include<bits/stdc++.h>
using namespace std;

const int mod=998244353; 
const int N=520,M=110;
long long dp[N][N*M],cnt[N][N*M],MAXN=0;
long long n,a[N];
long long ans=0;

void solve1(){
	sort(a+1,a+1+n);
	cnt[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=MAXN*n;j++){
			cnt[i][j]=cnt[i-1][j];
			if(j>=a[i])cnt[i][j]+=cnt[i-1][j-a[i]]; 
			
			dp[i][j]=dp[i-1][j];
			if(j>a[i]*2) dp[i][j]+=cnt[i-1][j-a[i]];
			
			dp[i][j]%=mod;
			cnt[i][j]%=mod;
			 
//			cout<<dp[i][j]<<' ';
		}
//		cout<<'\n';
	}
	for(int i=0;i<=MAXN*n;i++)
		ans+=dp[n][i],ans%=mod;
	cout<<ans;
}

void solve2(){
	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		MAXN=max(MAXN,a[i]);
	}
	if(n<=500&&MAXN<=100||n<=5000&&MAXN==1) solve1();
	else solve2();
	return 0;
} 