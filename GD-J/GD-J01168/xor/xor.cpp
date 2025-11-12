#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
int dp[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int j,cnt;
	int bj=0;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		//优化算法版本 
		j=i-1,cnt=a[i];
		while(j>bj&&cnt!=k){
			cnt^=a[j];
			j--;
		} 
		if(cnt==k){
			dp[i]=max(dp[i],dp[j]+1);
			bj=i;
		}
	}
	cout<<dp[n];
	return 0;
} 
