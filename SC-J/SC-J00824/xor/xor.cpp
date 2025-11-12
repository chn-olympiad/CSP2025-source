#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int INF=2e6+10;
int a[INF],lst[INF],q[INF],ans;
int dp[INF][2];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,k;cin>>n>>k;
	memset(lst,-1,sizeof(lst));
	lst[0]=0;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		q[i]=q[i-1]^a[i];
		int pos=q[i]^k;
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
		if (lst[pos]>=0)dp[i][1]=max(dp[lst[pos]][0],dp[lst[pos]][1])+1;
		lst[q[i]]=i;
	} 
	cout<<max(dp[n][0],dp[n][1]);
	return 0;
}
