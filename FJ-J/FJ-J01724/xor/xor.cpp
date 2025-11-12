#include<bits/stdc++.h>
using namespace std;
int n;
long long k;
long long a[500050];
long long sum[500050];
long long dp[500050];
long long tmp[500050];
int vis[5000050];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		if(k==sum[i]||vis[k^sum[i]])dp[i]=max(dp[i-1],dp[vis[k^sum[i]]]+1);
		else dp[i]=dp[i-1];
		if(dp[i]>=dp[vis[sum[i]]])vis[sum[i]]=i;
	} 
	cout<<dp[n]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
