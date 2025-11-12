#include<bits/stdc++.h>
using namespace std;
const int N=514514;
long long n,k,a,E=0,d[N],dp[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a);
		d[i]=d[i-1]^a;
		if(a==1) E++;
	}
	if(E==n){
		if(k==1) cout<<n;
		else if(k==0) cout<<n/2;
		else cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=1;j<=i;j++){
			long long p=d[i]^d[j-1];
			if(p==k)
				dp[i]=max(dp[i],dp[j-1]+1);
		}
	}
	cout<<dp[n];
	return 0;
}
