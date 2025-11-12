#include <bits/stdc++.h>
using namespace std;
int n,k,s=1;
int a[500005],q[500005];
map<int,int> f,w;
int dp[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	f[0]=true;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		q[i]=q[i-1]^a[i];
		w[i]=f[q[i]];
		f[(q[i]^k)]=i;
	}
	dp[0]=-1;
	for(int i=s;i<=n;i++){
		if(a[i]==k) dp[i]=max(dp[i-1]+1,1);
		else dp[i]=max(dp[w[i]]+1,dp[i-1]);
		if(q[i]==k) dp[i]=max(dp[i],1);
	}
	printf("%d",dp[n]);
	return 0;
}
