#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n];
	vector<int>dp(n,1);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		for(int j=i;j<n;j++){
			if(a[i-1]^a[j]==k){
				dp[j]=max(dp[j],dp[i-1]+1);
			}
		}
	}
	int mx=0;
	for(int i=0;i<n;i++){
		mx=max(mx,dp[i]);
	}
	cout<<mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
