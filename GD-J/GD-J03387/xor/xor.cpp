#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int sum[500005];
int dp[500005],dp2[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	memset(dp,0,sizeof(dp));
	memset(dp2,0,sizeof(dp2));
	int ls,ls2;
	for(int i=1;i<=n;i++){
		dp2[i]=dp2[i-1],dp[i]=0;
		cin>>ls;
		sum[i]=sum[i-1]^ls;
		for(int j=i-1;j>=0;j--){
			ls2=sum[i];
			ls2^=sum[j];
			if(ls2==k){
				dp[i]=dp2[j]+1;
				dp2[i]=max(dp2[i],dp[i]);
				break;
			}
		}
	}
	cout<<dp2[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
