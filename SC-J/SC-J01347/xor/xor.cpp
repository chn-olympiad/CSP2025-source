#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N],b[N];
int dp[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int t=a[i];
		dp[i]=dp[i-1];
		for(int j=i;j>=1;j--){
			if(j!=i)t^=a[j];
			if(t==k){
				dp[i]=max(dp[i],dp[j-1]+1);
				break;
			}	
		}
	}
	cout<<dp[n];
	return 0;
} 