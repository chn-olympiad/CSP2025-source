#include<iostream>
using namespace std;
long long n,k;
long long a[5000005];
long long dp[5000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=a[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j<i)dp[j]=dp[j];
			else{
				if((a[j]^a[i-1])==k){
					dp[j]=dp[i-1]+1;
				}
				else dp[j]=max(dp[j],dp[j-1]);
			}
		}
	}
	cout<<dp[n];
	return 0;
}
