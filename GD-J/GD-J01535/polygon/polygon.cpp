#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
struct code{
	int sum,type;
};
int a[500010],sum[500010],maxn,f[5010][5010];
code dp[5010][5010];
signed main(){
	//freopen("polyyon.in","r",stdin);
	//freopen("polyyon.out","w",stdout);
	//cout<<(int)(sizeof dp)/1024/1024<<'\n';
	cin>>n;
	if(n<3){
		cout<<0<<'\n';
		return 0;
	} 
	sum[0]=0;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
		maxn=max(maxn,a[i]);
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*maxn){
			cout<<1<<'\n'; 
		}
		else {
			cout<<0<<'\n';
		}
		return 0;
	}
	sort(a+1,a+n+1);
	int cnt=0;
	for (int i=1;i<=n;i++){
		dp[i][i].sum=0;
		dp[i][i].type=1;
		dp[i][i-1].sum=0;
		dp[i][i-1].type=1;
		dp[i][i-2].type=1;
		dp[i][i-2].sum=0;
		dp[i][0].sum=sum[i];
	}
	
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			dp[i][j].sum=dp[i-1][j-1].sum;
			dp[i][j].type=(dp[i-1][j-1].type+mod)%mod;
			if(dp[i-1][j].sum>a[j]) {
				dp[i][j].type+=(dp[i-1][j].type+mod)%mod;
				dp[i][j].sum+=a[j]+dp[i-1][j].sum;
			}
			
		}
	}
	for (int i=1;i<=n;i++){
		cnt+=dp[n][i].type;
		//cout<<dp[n][i].type<<'\n';
	}
	cout<<cnt;
	return 0;
}
