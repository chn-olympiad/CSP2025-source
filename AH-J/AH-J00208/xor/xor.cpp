#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,k,a[MAXN];
int s[MAXN],dp[MAXN];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]^a[i];
	}
	if(n<=1e3){
		for(int i=1;i<=n;i++){
			dp[i]=dp[i-1];
			for(int j=0;j<i;j++){
				dp[i]=max(dp[i],dp[j]+((s[i]^s[j])==k));
			}
		}
		cout<<dp[n];
	}
	else{
		for(int i=1;i<=n;i++){
			dp[i]=dp[i-1];
			for(int j=i-1;j>=0&&dp[j]==dp[i];j--){
				if((s[i]^s[j])==k){
					dp[i]++;
					break;
				}
			}
		}
		cout<<dp[n];
	}
	return 0;
}
