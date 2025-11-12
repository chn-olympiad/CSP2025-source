#include<bits/stdc++.h>
#define int long long
#define fre(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout);
using namespace std;
const int N=5e5+5;
int n,k,a[N],dp[N],d[N];
signed main(){
	fre("xor");
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){cin>>a[i];d[i]=d[i-1]^a[i];}
	for(int i=1;i<=n;i++){
		int idx=i;
		while(idx>0&&(d[i]^d[idx-1])!=k)--idx;
		if(idx==0)dp[i]=dp[i-1];
		else dp[i]=max(dp[idx-1]+1,dp[i-1]);
	}
	cout<<dp[n]<<"\n";
	return 0;
}