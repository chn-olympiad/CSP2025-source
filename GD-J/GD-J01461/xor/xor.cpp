#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int pre[500005];
int dp[500005];
int ValXor[1050000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(ValXor,-1,sizeof ValXor);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1];
		pre[i]^=a[i];
	}
	ValXor[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		int temp=k^pre[i];
		if(ValXor[temp]!=-1)dp[i]=max(dp[i],dp[ValXor[temp]]+1);
		ValXor[pre[i]]=i;
	}
	cout<<dp[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
