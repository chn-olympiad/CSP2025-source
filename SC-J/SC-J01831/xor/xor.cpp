#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5; 
int n,k,a[N],p[N*2],pre[N],dp[N];
void init(){
	int sum=0;
	for(int i=1;i<=n;i++)pre[i]=-1;
	for(int i=1;i<N;i++)p[i]=-1;
	for(int i=1;i<=n;i++){
		sum=(sum^a[i]);
		if(p[(sum^k)]!=-1)pre[i]=p[(sum^k)];
		p[sum]=i;
	}
	return ;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	init();
	for(int i=1;i<=n;i++){
		if(pre[i]!=-1)dp[i]=max(dp[i-1],dp[pre[i]]+1);
		else dp[i]=dp[i-1];
	}
	cout<<dp[n];
	return 0;
}