#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],ln[N],p[N],q[N],dp[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i],ln[i]=(ln[i-1]^a[i]);
	memset(p,-1,sizeof(p));
	p[0]=0;
	for(int i=1;i<=n;i++){
		int tt=(ln[i]^k);
		q[i]=p[tt];
		p[ln[i]]=i;
	}int ans=0;
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if(q[i]>=0)dp[i]=max(dp[i-1],dp[q[i]]+1);
	}cout<<dp[n];
	return 0;
} 
