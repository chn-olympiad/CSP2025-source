#include<bits/stdc++.h>
#define N 5001
#define inf 998244353
using namespace std;
int n,a[N],pre[N],dp[N];
long long ans;
inline solve(int ma){
	for(int i=1;i<ma;i++){
		for(int j=pre[ma-1];j>=3;j--){
			dp[j]=max(dp[j],dp[j]=dp[j-pre[i]]+pre[i]);
			if(pre[ma-1]-dp[j]>=a[ma])ans++;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=3;i--)solve(i);
	cout<<ans%inf;
	return 0;
}

