#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5005;
const int M=998244353;

int n;
int a[maxn];
int tong[maxn];
int dp[maxn+1][maxn+1];
int ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0,tmp;i<n;++i){
		cin>>tmp;
		++tong[tmp];
	}
	for(int i=1,cnt=0;i<=maxn;++i){
		for(int j=0;j<tong[i];++j){
			a[++cnt]=i;
		}
	}
//	for(int i=1;i<=n;++i){
//		cout<<a[i]<<' ';
//	}cout<<'\n';
	dp[0][0]=1;
	for(int i=1;i<n;++i){
		dp[i][0]=dp[i-1][0]<<1;
		dp[i][0]%=M;
	}
	for(int i=1;i<=n;++i){
//		cout<<dp[i-1][0]<<' ';
		for(int j=1;j<a[i];++j){
			dp[i][j]=dp[i-1][j]+dp[i-1][0];
			dp[i][j]%=M;
//			cout<<dp[i-1][j]<<' ';
		}
		for(int j=a[i];j<=maxn;++j){
			dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i]];
			dp[i][j]%=M;
//			cout<<dp[i-1][j]<<' ';
		}
//		cout<<'\n';
		ans+=dp[i-1][a[i]+1];
		ans%=M;
	} 
	cout<<ans;
	return 0;
}
