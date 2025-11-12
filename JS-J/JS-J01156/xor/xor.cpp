#include<bits/stdc++.h>
using namespace std;
int n, k, a[500005];
long long dp[500005];
bool work(int x, int y){
	int cnt=0;
	for(int l=x; l<=y; l++){
		cnt+=a[l];
	}
	return cnt==k;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			dp[i]=max(dp[i],dp[j]+work(j,i));
		}
	}
	cout<<dp[n];
	return 0;
}
