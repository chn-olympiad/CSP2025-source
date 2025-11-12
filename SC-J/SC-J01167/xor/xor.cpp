#include<bits/stdc++.h>
using namespace std;
const int N=5e6+100;
int a[N],s[N],dp[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int l=1;l<=n;l++){
			int j=i+l-1;
			if(j>n) break;
			if((s[j]^s[i-1])==k)
			dp[j]=max(dp[j],dp[i-1]+1);
			else dp[j]=max(dp[j],dp[j-1]);
		}
	}
	cout<<dp[n];
	return 0;
}