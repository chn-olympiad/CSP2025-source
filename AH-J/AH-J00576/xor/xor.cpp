#include <bits/stdc++.h>
using namespace std;
int n,k,a[500001],b[500001];
int dp[500001];
int main(){
    freopen("xor6.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=b[i-1]^a[i];
    }for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((b[j]^b[i-1])==k){
                dp[j]=max(dp[i-1]+1,max(dp[j-1],dp[j]));
            }else{
                dp[j]=max(dp[j-1],dp[j]);
            }
        }
    }printf("%d",dp[n]);
}
