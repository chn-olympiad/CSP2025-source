#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=(1<<20)+5;
int n,k,a[N],dp[256],ans,maxi,x;
int main(){
	freopen("xor.in","r",stdin),freopen("xor.out","w",stdout);
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)dp[x]=maxi=max(maxi,dp[k^x]+1),ans=max(ans,dp[k^(x^=a[i])]);
	cout<<ans;
	return 0;
}
