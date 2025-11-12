#include<bits/stdc++.h>
using namespace std;
int n,k;
int tj[1<<21];
bool bj[1<<21];
int a[500005];
int dp[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	bj[0]=1;
	int xsum=0;
	for(int i=1;i<=n;i++){
		xsum=xsum^a[i];
		dp[i]=dp[i-1];
		if(bj[xsum^k])
			dp[i]=max(dp[i],dp[tj[xsum^k]]+1);
		tj[xsum]=i;
		bj[xsum]=1;
	}
	cout<<dp[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
