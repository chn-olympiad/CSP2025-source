#include<bits/stdc++.h>
#include<stack>

using namespace std;

/*
-1834379501
0^0=0
1^0=1
0^1=1
1^1=0

p ^ q ^ q <=> p
p ^ p ^ q <=> q
p^q<->k <=> p^k<->q

Sum-Prefix.
*/

int n,k,sum[500010] = {0},dp[500010]={0},ans=0;

void dfs(int l,int cnt) {
	if(l>n) {
		ans = max(ans,cnt);
		return;
	}
	dp[l] = cnt;
	for(int r=l;r<=n;r++) {
		if((sum[l-1]^sum[r])==k) {
			if(dp[r+1]<cnt+1) 	dfs(r+1,cnt+1);
		} else {
			if(dp[r+1]<cnt)		dfs(r+1,cnt);
		}
	}
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	scanf("%d%d",&n,&k);
	
	for(int i=1;i<=n+5;i++) dp[i] = -1;
	
	for(int i=1;i<=n;i++) {
		int temp;
		scanf("%d",&temp);
		sum[i] = sum[i-1] ^ temp;
	}
	
	dfs(1,0);
	
	printf("%d\n",ans);
	
	return 0;
}
