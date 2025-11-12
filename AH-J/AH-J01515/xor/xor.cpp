#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],q[500005],dp[500005],x,maxn;
int t[1100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	memset(t,-1,sizeof t);
	t[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q[i]=q[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		x=k^q[i];
		if(t[x]!=-1)
			dp[i]=max(dp[i],dp[t[x]]+1);
		t[q[i]]=i;
	}
	cout<<dp[n];
	return 0;
}
