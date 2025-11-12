#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010],sum[500010],ans;
int tree[5000010];
int dp[500010][2];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(tree,-1,sizeof(tree));
	tree[0]=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
		dp[i][1]=tree[sum[i]^k]+1;
		tree[sum[i]]=max(tree[sum[i]],max(dp[i][0],dp[i][1]));
	}
	ans=max(dp[n][0],dp[n][1]);
	cout<<ans;
	return 0;
}
/*
zno CCF orz
zno DuZiDe orz
zno CCF orz
zno DuZiDe orz
zno CCF orz
zno DuZiDe orz
zno CCF orz
zno DuZiDe orz
zno CCF orz
zno DuZiDe orz

mi huo xing wei da shang
*/
