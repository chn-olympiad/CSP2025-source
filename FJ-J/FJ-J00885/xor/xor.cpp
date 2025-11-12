#include<bits/stdc++.h>
using namespace std;
long long n,k,ans=0;
long long sum[500005],a[500005],dp[500005],y[500005];
int deal(int l,int r){
	int sum22=a[l];
	if(l==r) return sum22;
	for(int i=l+1;i<=r;i++){
		sum22=sum22^a[i];
		
	}
	return sum22;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	scanf("%lld %lld",&n,&k);
	
	
	scanf("%lld",&a[1]);
	
	
	for(int i=2;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		y[i]=a[i];
		for(int q=i;q>=1;q--){
//			int y=deal(i,q);
			if(q==i) ;
			else
			y[q]=y[q+1]^a[q];
		    
			if(y[q]==k){
				
				dp[i]=max(dp[q-1]+1,dp[i]);
				break;
				
			}
			
			
		}
		
	}
	printf("%lld",dp[n]);
	return 0;
}
