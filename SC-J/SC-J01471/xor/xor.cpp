#include <bits/stdc++.h>
using namespace std;

const int N=5e5+5,M=1e6+1e5;
int n,k,a[N],dp[N],pre[N],ans[M];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),pre[i]=pre[i-1]^a[i];
	for(int i=1;i<=M-5;i++)
		ans[i]=-1;
	for(int i=1;i<=n+1;i++)
		dp[i]=-1e9;
	for(int i=1;i<=n;i++){
		int front=k^pre[i];
		dp[i]=max(dp[i],dp[i-1]);
		if(ans[front]!=-1)
			dp[i]=max(dp[i],dp[ans[front]]+1);
		ans[pre[i]]=i;
	}
	printf("%d",dp[n]);
	return 0;
}