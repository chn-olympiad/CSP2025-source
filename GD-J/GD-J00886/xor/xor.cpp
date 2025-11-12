#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],pre[N];
int dp[N];
int n,k;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if((pre[j-1]^pre[i])==k){
				dp[i]=max(dp[i],dp[j-1]+1);
			}else dp[i]=max(dp[i-1],dp[i]);
		}
	} 
	cout<<dp[n];
	return 0;
} 

