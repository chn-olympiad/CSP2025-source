#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int dp[1001][1001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        int sum=a[i];
        if(sum==k) dp[i][i]=1;
        for(int j=i+1;j<=n;j++){
            sum=sum^a[j];
            if(sum==k) dp[i][j]=1;
        }
    }
    for(int len=1;len<=n;len++){
        for(int l=1;l+len-1<=n;l++){
            int r=l+len-1;
            for(int i=l;i<r;i++) dp[l][r]=max(dp[l][r],dp[l][i]+dp[i+1][r]);
        }
    }
    printf("%d",dp[1][n]);
    return 0;
}
