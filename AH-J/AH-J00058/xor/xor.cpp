#include<bits/stdc++.h>
using namespace std;
int n,k;
int t[4500005];
int pre[500005];
int x;
int xoxor;
int dp[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=0;i<=(1<<20);i++)t[i]=-1;
	t[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		xoxor ^= x;
		pre[i]=-1;
		dp[i]=dp[i-1];
		if(t[xoxor ^ k]!=-1){
			pre[i]=t[xoxor ^ k];
			dp[i]=max(dp[i],dp[pre[i]]+1);
		}
		t[xoxor]=i;
	}
	printf("%d\n",dp[n]);
	return 0;
}
