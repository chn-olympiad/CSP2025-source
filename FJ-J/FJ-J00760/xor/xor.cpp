#include<bits/stdc++.h>
using namespace std;
int n,k,a,x,ne[2000000],dp[500002];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	memset(ne,-0x3f,sizeof ne),ne[0]=0;
	for(int i=1,j;i<=n;i++){
		scanf("%d",&a);
		x^=a,j=ne[x^k],dp[i]=dp[i-1];
		if(j>=0)dp[i]=max(dp[i],dp[j]+1);
		ne[x]=i;
	}
	cout<<dp[n];
	return 0;
} 
