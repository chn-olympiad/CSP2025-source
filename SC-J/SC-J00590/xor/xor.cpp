#include <bits/stdc++.h>
using namespace std;
const int N=500100;
long long a[N],l[N],dp[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]=(a[i-1] xor x);
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i-1;j>=0;j--){
			if((a[j] xor a[i])==k){l[i]=j+1;break;}
		}
	}
	for(long long i=1;i<=n;i++){
		if(l[i]==0) dp[i]=dp[i-1];
		else dp[i]=max(dp[l[i]-1]+1,dp[i-1]);
	}
	cout<<dp[n];
	return 0;
}