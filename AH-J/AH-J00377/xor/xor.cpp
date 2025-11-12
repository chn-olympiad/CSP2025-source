#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],dp[500005];
int d[(1<<20)];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	memset(d,-1,sizeof(d));
	int qzh=0; d[0]=0;
	for(int i=1;i<=n;i++){
		qzh^=a[i];
		int zy=qzh^k;
		dp[i]=dp[i-1];
		if(~d[zy])dp[i]=max(dp[i],d[zy]+1);
		d[qzh]=max(d[qzh],dp[i]);
	}
	cout<<max(dp[n],0)<<endl;
	return 0;
}
