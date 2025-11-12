#include<bits/stdc++.h>
using namespace std;
const int MAXN=5*1e5+5;
int n,k,a[MAXN],dp[MAXN];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=a[1],l=1;
	for(int i=1;i<=n;i++){
		if(i!=l) sum^=a[i];
		dp[i]=max(dp[i],dp[i-1]);
		if(a[i]==k){
			if(dp[i-1]+1>dp[i]){
				dp[i]=dp[i-1]+1;
				sum=a[i+1];
				l=i+1;
			}
		}else if(sum==k&&l!=i){
			if(dp[l-1]+1>dp[i]){
				dp[i]=dp[l-1]+1;
				sum=a[i+1];
				l=i+1;
			}
		}else if(sum>k&&l!=i){
			if((sum^a[l])==k){
				dp[i]=max(dp[i],dp[l+1]+1);
			}
			sum=a[i+1];
			l=i+1;
		}
	}
	cout<<dp[n];
	return 0;
}
