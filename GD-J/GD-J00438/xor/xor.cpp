#include<bits/stdc++.h>
using namespace std;
int k,n,dp[500005],a[500005];bool l[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]); 
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if(a[i]==k){
			dp[i]++;l[i]=1;
		}
		else{
			int o=a[i];
			for(int j=i-1;j>=1;j--){
				if(l[j]==1)break;
				else {
					o^=a[j];
				    if(o==k){
					
					    for(int k=j;k<=i;k++){
						 l[k]=1;
					    }dp[i]++;
					    break;
				    }
				}
				
			}
		}
	}
	printf("%d",dp[n]);
	return 0;
}

