#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=(1<<20);
int n,k,a[N],dp[N],pre[M+5];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<M;i++)
		pre[i]=-1;
	pre[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]^=a[i-1];
		dp[i]=dp[i-1];
		if(pre[a[i]^k]!=-1)dp[i]=max(dp[i],dp[pre[a[i]^k]]+1);
		pre[a[i]]=i;
	}
	cout<<dp[n]<<"\n";
	return 0;
} 
