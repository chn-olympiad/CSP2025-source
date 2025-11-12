#include<bits/stdc++.h>
using namespace std;
int N=998244353;
int n,l=0,cnt=0;
int a[5007];
int dp[507][999999];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    memset(dp,0,sizeof(dp));
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    dp[0][0]=1;
    dp[0][1]=0;
    for(int i=1;i<=n;i++){
        for(int j=l;j>=0;j--){
            for(int k=1;k<=dp[j][0];k++){
                dp[j+1][0]++;
                dp[j+1][dp[j+1][0]]=a[i]+dp[j][k];
                if(dp[j][k]>a[i]&&j>=2) cnt=(cnt+1)%N;
            }
        }
        l++;
    }
    printf("%d",cnt);
    return 0;
}
