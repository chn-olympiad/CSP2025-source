#include<bits/stdc++.h>
using namespace std;

const int N=1e6+2e5+10;
int dp[N];
int n,k;
int a[N],sum[N],cnt[N],pre[N];

void solve1(){
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]^a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			dp[i]=max(dp[i],dp[i-1]);
			if((sum[i]^sum[j-1])==k)
				dp[i]=max(dp[i],dp[j-1]+1);
		} 
//		cout<<dp[i]<<' ';
	}
//	cout<<'\n'; 
	cout<<dp[n];
} 

void solve2(){
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]^a[i];
		pre[i]=cnt[sum[i]];
		cnt[sum[i]^k]=i;
	}
		
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if(pre[i]>0) dp[i]=max(dp[i],dp[pre[i]]+1);
//		cout<<dp[i]<<' ';
	}
//	cout<<'\n'; 
	cout<<dp[n];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=1000)solve1(); 
	else solve2();
	
	return 0;
} 