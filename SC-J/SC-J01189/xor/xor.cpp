#include<bits/stdc++.h> 
using namespace std;
const int maxn=5*1e5+5;
long long n,k,a[maxn],dp[maxn];
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=1;j<=n;j++){
			if(j==0){
				if(a[i]==k){
					dp[i]++;
				}
			}
			long long b=0;
			for(int s=i-j;s<=i;s++){
				b^=a[s];
			}
			if(b==k){
				dp[i]=max(dp[i],dp[i-j]+1);
			}
		} 
	}
	cout<<dp[n]; 
	return 0;
}