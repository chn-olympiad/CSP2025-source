#include<bits/stdc++.h>
using namespace std;
const int N=500050;
int a[N];
int qz[N]; 
long long dp[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		qz[i]=(qz[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if(a[i]==k)dp[i]=dp[i-1]+1;
		else{
			for(int j=i-1;j>=1;j--){
				if((qz[i]^qz[j-1])==k){
					dp[i]=max(dp[i],dp[j-1]+1);
					break;
				}
			}
		}
	}
	cout<<dp[n];
	return 0;
}
