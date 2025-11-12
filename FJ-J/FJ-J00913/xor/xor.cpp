#include<bits/stdc++.h>
using namespace std;
long long n,k,s,x,ans,dp[500005],a[1050000]; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<(1<<20);i++)a[i]=-1;
	for(int i=1;i<=n;i++)cin>>x,s^=x,a[s]=dp[i]=max(dp[i-1],a[s^k]+1);
	cout<<dp[n];
	return 0;
}

