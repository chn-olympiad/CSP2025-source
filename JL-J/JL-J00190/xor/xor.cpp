#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],dp[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(k<=1){
        int up=0,xo=0,l=1;
        for(int i=1;i<=n;i++){
            xo^=a[i];
            if(a[i]==k){
                up=i;
                xo=0;
                dp[i]=dp[i-1]+1;
            }
            else if(xo==k){
                dp[i]=max(dp[i-1],dp[i-up]+1);
                if(dp[i]==dp[i-up]+1){
                    xo=0;
                    up=i;
                }
                else{
                    l++;
                    xo=0;
                    i=l;
                }
            }
            else dp[i]=dp[i-1];
        }
        printf("%d",dp[n]);
        return 0;
    }
    int up=0,cnt=0,mx=INT_MIN;
    for(int x=1;x<=n;x++){
        cnt=0;
        for(int i=x;i<=n;i++){
            for(int j=i;j<=n;j++){
                int xo=a[i];
                for(int k=i+1;k<=j;k++){
                    xo^=a[k];
                }
                if(xo==k){
                    cnt++,i=j;
                }
            }
        }
        mx=max(mx,cnt);
    }
    printf("%d",mx);
    return 0;
}
