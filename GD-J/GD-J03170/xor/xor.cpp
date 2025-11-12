#include<bits/stdc++.h>
using namespace std;
int n,ke,a[500005],prv[(1<<21)],s[500005],dp[500005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>ke;
	for(int i=1;i<=n;i++) cin>>a[i],s[i]=(s[i-1]^a[i]);
//	for(int i=1;i<=n;i++) f[i][i]=(a[i]==ke);
//	for(int l=2;l<=n;l++){
//		for(int i=1,j=l;j<=n;i++,j++){
//			f[i][j]=((s[j]^s[i-1])==ke);
//			for(int k=i;k<j;k++) 
//			f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]);
//		}
//	} 
//	cout<<f[1][n];
//	//O(n*n*n) 期望40pts
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1]+(a[i]==ke);
		if(s[i]==ke) dp[i]=max(dp[i],1); //特判prv==0 
		if(prv[s[i]^ke]) dp[i]=max(dp[i],dp[prv[s[i]^ke]]+1);
		prv[s[i]]=i;
		ans=max(ans,dp[i]);
	}//O(n) 期望 100pts
	//拿下！ 
	cout<<ans;
	return 0;
}
