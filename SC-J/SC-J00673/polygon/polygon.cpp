#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi pair<int,int>
#define ull unsigned long long
const int mod=998244353;
const int N=5010;
int a[N];
int dp[N],g[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dp[0]=1;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=a[i]+1;j<N;j++){
			ans=(ans+dp[j])%mod;
		}
		memcpy(g,dp,sizeof g);
		for(int j=0;j<N;j++){
			dp[min(j+a[i],N-1)]=(dp[min(j+a[i],N-1)]+g[j])%mod;
		}
	}
	cout<<ans;
	return 0;
}