#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;
inline int add(const int &a,const int &b){
    return (a+b>=mod)?(a+b-mod):(a+b);
}
inline int mul(const int &a,const int &b){
    return 1ll*a*b%mod;
}
inline int del(const int &a,const int &b){
    return (a<b)?(a-b+mod):(a-b);
}
const int maxn=5e3+10;

int arr[maxn],dp[maxn];
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,m=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        m=max(m,arr[i]);
    }
    sort(arr+1,arr+1+n);
    dp[0]=1;
 //  fprintf(stderr,"%d\n",m);
    int ans=0,res=1;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=arr[i];j--){
            dp[j]=add(dp[j],dp[j-arr[i]]);
        }
        // for(int j=0;j<=m;j++){
        //     fprintf(stderr,"%d ",dp[j]);
        // }
       // fprintf(stderr," ");
        res=mul(res,2);
        if(i!=n){
            ans=add(ans,res);
            for(int j=0;j<=arr[i+1];j++){
                ans=del(ans,dp[j]);
            }
        }

       // fprintf(stderr,"ans:%d\n",ans);
    }
    printf("%d\n",ans);
    return 0;
}