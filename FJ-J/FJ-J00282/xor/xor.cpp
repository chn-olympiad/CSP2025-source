#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5 +5;
int sum[N],a[N],k,n,dp[N],last[N],has[N<<2];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;has[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		if(a[i]==k)last[i]=i;
		else if(has[sum[i]^k])last[i]=has[sum[i]^k];
		has[sum[i]]=i+1;
	}
	for(int i=1;i<=n;i++)dp[i]=max(dp[i-1],last[i]?dp[last[i]-1]+1:0);
	cout<<dp[n];
	return 0;
}
// lztm
