#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
int b[2000010];
int dp[500010];
int t;
int sum;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	memset(b,128,sizeof(b));
	t=b[0];
	b[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum=sum^a[i];
		dp[i]=dp[i-1];
		if(b[sum^k]!=t)dp[i]=max(dp[i],dp[b[sum^k]]+1);
		if(b[sum]==t||dp[b[sum]]<dp[i])b[sum]=i;
	}
	cout<<dp[n];
	return 0;
}

