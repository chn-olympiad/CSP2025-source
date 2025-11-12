#include<bits/stdc++.h>
using namespace std;
const int N=5e5+55;
int n,k,a[N],q[N],dp[N],v[1<<21];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q[i]=q[i-1]^a[i];
	}
	if(a[1]==k)dp[1]=1;
	else dp[1]=0;
	v[a[1]]=1,v[0]=1;
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1];
		if(v[q[i]^k]>0)dp[i]=max(dp[i],dp[v[q[i]^k]]+1);
		v[q[i]]=i;
	}
	cout<<dp[n];
	return 0;
}
