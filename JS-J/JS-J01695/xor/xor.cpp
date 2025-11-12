#include<bits/stdc++.h>

using namespace std;

const int N = 5e5+5;

int a[N];
int n,k;
int pre[N];
int mx[1<<21],dp[N];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		pre[i]=(pre[i-1]^a[i]);
	memset(mx,-0x3f,sizeof(mx));
	memset(dp,-0x3f,sizeof(dp));
	dp[0]=0,mx[0]=0;
	int mxall=0;
	for(int i=1;i<=n;i++){
		dp[i]=max(mx[pre[i]^k]+1,mxall);
		mx[pre[i]]=max(mx[pre[i]],dp[i]);
		mxall=max(mxall,dp[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,dp[i]);
	printf("%d\n",ans);
	return 0;
}