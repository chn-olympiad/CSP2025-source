#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,tal[500001],pre[500001],dp[500001],g_num1;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>tal[i];
		if(tal[i]==1)++g_num1;
		pre[i]=(pre[i-1]^tal[i]);
	}
	if(k==1)cout<<g_num1;
	else if(k==0)cout<<n-g_num1;
	else{
		dp[1]=0;
		if(tal[1]==k)dp[1]=1;
		for(int i=1;i<=n;i++){
			dp[i]=max(dp[i],dp[i-1]);
			if(pre[i]==k)dp[i]=max(dp[i],dp[i-1]+1);
		}
		cout<<dp[n];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
