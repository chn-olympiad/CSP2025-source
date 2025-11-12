#include<iostream>

using namespace std;

int n,k;
int a[1000001],qz[1000001];
int dp[1000001];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		qz[i]=a[i]^qz[i-1];
	}
	int temp=1;
	for(int i=1;i<=n;i++){
		if((qz[i]^qz[temp-1])==k){
			dp[i]=dp[temp-1]+1;
			temp=i+1; 
		}else{
			dp[i]=dp[temp-1];
		}
	}
	
	int ans=-1e9; 
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
