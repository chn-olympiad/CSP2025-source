#include<bits/stdc++.h>
using namespace std;
int n,k;
long long a[500005];
bool f[100005];
long long dp[100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	dp[0]=0;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			dp[i]=dp[i-1]+1;
		}
		else{
			int o=-1;
			int ll=a[i];
			for(int j=i-1;j>=1;j--){
				ll=ll^a[j];
				if(ll==k){
					o=j;
					break;	
				}
			}
			if(o!=-1)dp[i]=max(dp[i-1],dp[o-1]+1);
			else dp[i]=dp[i-1];
			
		}
	}
	cout<<dp[n];
	return 0;
}
