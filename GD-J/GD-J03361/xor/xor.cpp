#include<bits/stdc++.h>
using namespace std;
int a[500001];
int dp[500001];
//int vit[500001];
int n;
int k;
int s(int x,int y){
	int u=a[x];
	for(int i=x+1;i<=y;i++){
		u^=a[i];
	}
	return u;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=i;j>=1;j--){
			if(s(j,i)==k){
			//	y=true;
				dp[i]=max(dp[i],dp[j-1]+1);
				break;
			}
		}
		
			
		
	}
	cout<<dp[n];

	return 0;
}

