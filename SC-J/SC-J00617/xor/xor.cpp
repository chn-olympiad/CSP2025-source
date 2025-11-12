#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3;
int n,k,a[N],dp[N],t[1<<21],p[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i]=p[i-1]^a[i];
		dp[i]=dp[i-1];
		if(t[p[i]^k]||p[i]==k)	dp[i]=max(dp[i],dp[t[p[i]^k]]+1);
		t[p[i]]=i;
	}
	cout<<dp[n];
	return 0;
}