#include<bits/stdc++.h>
using namespace std;
int n,k;
int px[500010],dp[500010];
int vec[1050010];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	memset(vec,-1,sizeof(vec));
	vec[0]=0;
	for(int i=1;i<=n;i++){
		cin>>px[i];
		px[i]^=px[i-1];
//		cout<<px[i]<<",";
		if(vec[px[i]^k]!=-1)dp[i]=dp[vec[px[i]^k]]+1;
		dp[i]=max(dp[i],dp[i-1]);
//		cout<<dp[i]<<","<<vec[px[i]^k]<<"\n";
		vec[px[i]]=i;
	}
	cout<<dp[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
