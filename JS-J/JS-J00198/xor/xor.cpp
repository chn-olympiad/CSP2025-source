#include <bits/stdc++.h>
using namespace std;
int dp[500005],a[500005],n,k;
int main(){ 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int h=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int t=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			h=0;
			t=0;
			for(int l=i;l>=j;l--){
					t=t^a[l];
			}
			if(t==k){
				h=1;
			}
			dp[i]=max(dp[j-1]+h,dp[i]);
		}
	}
	cout<<dp[n];
    return 0;
}
