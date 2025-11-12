#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,k,a[N],b[N],dp[N];
map<int,int> f;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		a[i]^=a[i-1];
	}f[0]=0;
	for(int i=1; i<=n; i++) {
		int x=a[i]^k;
		if(f[x]==0&&x!=0)
			b[i]=-1;
		else
			b[i]=f[x];
		f[a[i]]=i;
	}
	for(int i=1; i<=n; i++) 
		if(b[i]!=-1) 
			dp[i]=max(dp[i-1],dp[b[i]]+1);
		 else 
			dp[i]=dp[i-1];
	cout<<dp[n]<<"\n";
	return 0;
}
