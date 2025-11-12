#include<bits/stdc++.h>
using namespace std;
int n,k,t,a[500005],cnt[1048576],pre[500005],dp[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)pre[i]=-1;
	for(int i=0;i<1048576;i++)cnt[i]=-1;
	cnt[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t^=a[i];
		if(cnt[t^k]>=0)pre[i]=cnt[t^k]+1;
		cnt[t]=i;
		dp[i]=dp[i-1];
		if(pre[i]>0)dp[i]=max(dp[i],dp[pre[i]-1]+1);
	}
	cout<<dp[n];
	return 0;
}
