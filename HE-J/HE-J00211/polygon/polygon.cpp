#include<bits/stdc++.h>
using namespace std;
int n,a[5010],maxn[5010]={0};
int dp[5010][5010],ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i][i]=a[i];
		maxn[i]=max(maxn[i-1],a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			dp[i][j]=dp[i][j-1]+a[j];
			if(dp[i][j]>maxn[j]*2&&j-i>=2){
				ans++;
				ans%=998244353;
			}ans++;
		}
	}
	cout<<ans;
	return 0;
}
