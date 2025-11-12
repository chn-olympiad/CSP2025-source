#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	vector<int>A(n+1),dp(n+1);
	for(int i=1;i<=n;i++)cin>>A[i];
	for(int i=2;i<=n;i++)A[i]=(A[i]^A[i-1]);
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=i;j>=1;j--){
			if(dp[j-1]<dp[i])break;
			if((A[i]^A[j-1])==k){
				dp[i]++;
				break;
			}
		}
	}
	cout<<dp[n];
	return 0;
}