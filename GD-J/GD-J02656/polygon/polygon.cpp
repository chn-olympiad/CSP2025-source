#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int maxn=5010;
int n;
int a[maxn];
int dp[maxn];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<+n;i++){
		cin>>a[i];
	}
    dp[0]=1;
	for (int i=1;i<=n;i++){//个数 
		for (int j=1;j<=n;j++){//方案  
			dp[j]=max(dp[j-1],dp[j-a[i]]+a[i]);
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}
