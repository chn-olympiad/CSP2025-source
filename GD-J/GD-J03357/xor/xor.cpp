#include<bits/stdc++.h>
using namespace std;
int n,k,a,q,i,p[1050000],dp[500005];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<1048576;i++)p[i]=-1000000;
	for(i=1;i<=n;i++){
		cin>>a;
		q^=a;
		p[q]=dp[i]=max(dp[i-1],p[q^k]+1);
	}
	return cout<<dp[n],0;
}
